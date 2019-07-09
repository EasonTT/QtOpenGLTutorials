#include "SimpleObject3D.h"

SimpleObject3D::SimpleObject3D() :
	indexBuffer(QOpenGLBuffer::IndexBuffer), texture(0) {
}

SimpleObject3D::SimpleObject3D(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, const QImage& image) :
	indexBuffer(QOpenGLBuffer::IndexBuffer), texture(0) {
	init(vertices, indices, image);
}

SimpleObject3D::~SimpleObject3D() {
	if(vertexBuffer.isCreated())
		vertexBuffer.destroy();
	if(indexBuffer.isCreated())
		indexBuffer.destroy();
	if (texture != 0) {
		if (texture->isCreated())
			texture->destroy();
	}
}

void SimpleObject3D::init(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, const QImage& image) {

	if (vertexBuffer.isCreated())
		vertexBuffer.destroy();
	if (indexBuffer.isCreated())
		indexBuffer.destroy();
	if (texture != 0) {
		if (texture->isCreated()) {
			delete texture;
			texture = 0;
		}
	}

	vertexBuffer.create();
	vertexBuffer.bind();
	vertexBuffer.allocate(vertices.constData(), vertices.size() * sizeof(Vertex));
	vertexBuffer.release();

	indexBuffer.create();
	indexBuffer.bind();
	indexBuffer.allocate(indices.constData(), indices.size() * sizeof(GLuint));
	indexBuffer.release();

	texture = new QOpenGLTexture(image.mirrored());

	// Set nearest filtering mode for texture minification
	texture->setMinificationFilter(QOpenGLTexture::Linear);

	// Set bilinear filtering mode for texture magnification
	texture->setMagnificationFilter(QOpenGLTexture::Linear);

	// Wrap texture coordinates by repreating
	// f. ex. texture coordinate (1.1, 1.2) is same as 0.1, 0.2;
	texture->setWrapMode(QOpenGLTexture::Repeat);

	modelMatrix.setToIdentity();
}

void SimpleObject3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {

	if (!vertexBuffer.isCreated() || !indexBuffer.isCreated()) return;

	texture->bind(0);
	shaderProgram->setUniformValue("u_texture", 0);
	shaderProgram->setUniformValue("u_modelMatrix", modelMatrix);

	vertexBuffer.bind();

	int offset = 0;

	int verLoc = shaderProgram->attributeLocation("a_position");
	shaderProgram->enableAttributeArray(verLoc);
	shaderProgram->setAttributeBuffer(verLoc, GL_FLOAT, offset, 3, sizeof(Vertex));

	offset += sizeof(QVector3D);

	int texLoc = shaderProgram->attributeLocation("a_texcoord");
	shaderProgram->enableAttributeArray(texLoc);
	shaderProgram->setAttributeBuffer(texLoc, GL_FLOAT, offset, 2, sizeof(Vertex));

	offset += sizeof(QVector2D);

	int normLoc = shaderProgram->attributeLocation("a_normal");
	shaderProgram->enableAttributeArray(normLoc);
	shaderProgram->setAttributeBuffer(normLoc, GL_FLOAT, offset, 3, sizeof(Vertex));

	indexBuffer.bind();

	functions->glDrawElements(GL_TRIANGLES, indexBuffer.size(), GL_UNSIGNED_INT, 0);

	vertexBuffer.release();
	indexBuffer.release();
	texture->release();
}

void SimpleObject3D::translate(const QVector3D& translateVector) {
	modelMatrix.translate(translateVector);
}
