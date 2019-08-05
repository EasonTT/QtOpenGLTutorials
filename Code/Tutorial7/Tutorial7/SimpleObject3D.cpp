#include "SimpleObject3D.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
SimpleObject3D::SimpleObject3D() :
	indexBuffer(QOpenGLBuffer::IndexBuffer), texture(0) {
	s = 1.0f;
}

/*
Description:
	This function is a constructor with vertices reference, indices reference, and texture image reference;
Input:
	@ const QVector<Vertex>& vertices: the vertex list of a given object;
	@ const QVector<GLuint>& indices: the index list of a given object;
	@ const QImage & image: a given texture image;
*/
SimpleObject3D::SimpleObject3D(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, const QImage& image) :
	indexBuffer(QOpenGLBuffer::IndexBuffer), texture(0) {
	s = 1.0f;
	init(vertices, indices, image);
}

/*
Description:
	This function is a destructor;
Input:
	@ void patameter: void;
*/
SimpleObject3D::~SimpleObject3D() {
	if (vertexBuffer.isCreated())
		vertexBuffer.destroy();
	if (indexBuffer.isCreated())
		indexBuffer.destroy();
	if (texture != 0) {
		if (texture->isCreated())
			texture->destroy();
	}
}

/*
Description:
	This function is used to initialize an object with its vertices reference, indices reference, and texture image reference;
Input:
	@ const QVector<Vertex>& vertices: the vertex list of a given object;
	@ const QVector<GLuint>& indices: the index list of a given object;
	@ const QImage & image: a given texture image;
*/
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
}

/*
Description:
	This function is used to rotate the object;
Input:
	@ const QQuaternion& r: a quaternion (scalar, x position, y position, and z position) for rotation;
Output:
	@ void returnValue: void;
*/
void SimpleObject3D::rotate(const QQuaternion& r) {
	this->r = r * this->r;
}

/*
Description:
	This function is used to translate the object;
Input:
	@ const QVector3D& t: a translation vector;
Output:
	@ void returnValue: void;
*/
void SimpleObject3D::translate(const QVector3D& t) {
	this->t += t;
}

/*
Description:
	This function is used to scale the object;
Input:
	@ const float& s: a scalar;
Output:
	@ void returnValue: void;
*/
void SimpleObject3D::scale(const float& s) {
	this->s *= s;
}

/*
Description:
	This function is used to set the global transform for the object;
Input:
	@ const QMatrix4x4& g: a global transformation;
Output:
	@ void returnValue: void;
*/
void SimpleObject3D::setGlobalTransform(const QMatrix4x4& g) {
	this->g = g;
}

/*
Description:
	This function is used to draw all the objects in a group, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
Input:
	@ QOpenGLShaderProgram* shaderProgram: the shader program used for loading shaders and passing parameters;
	@ QOpenGLFunctions* functions: the OpenGL functions used to drawing elements;
Output:
	@ void returnValue: void;
*/
void SimpleObject3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {

	if (!vertexBuffer.isCreated() || !indexBuffer.isCreated()) return;

	texture->bind(0);
	shaderProgram->setUniformValue("u_texture", 0);

	QMatrix4x4 modelMatrix;
	modelMatrix.setToIdentity();
	modelMatrix.translate(t);
	modelMatrix.rotate(r);
	modelMatrix.scale(s);
	modelMatrix = g * modelMatrix;

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