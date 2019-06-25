#include "Widget.h"

Widget::Widget(QWidget* parent) :
	QOpenGLWidget(parent)/*, texture(0), indexBuffer(QOpenGLBuffer::IndexBuffer)*/ {
}

Widget::~Widget() {
}

void Widget::initializeGL() {
	// clear the screen with black
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	// clear the scrren with red
	//glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// initialize shaders
	initShaders();
	initCube(1.0);
}

void Widget::resizeGL(int width, int height) {
	float aspect = width / (float)height;

	pMatrix.setToIdentity();
	pMatrix.perspective(45, aspect, 0.1f, 10.0f);
}

void Widget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	QMatrix4x4 vMatrix;
	vMatrix.setToIdentity();
	vMatrix.translate(0.0, 0.0, -5.0);
	//mMatrix.rotate(30, 1.0, 0.0, 0.0);
	//mMatrix.rotate(30, 0.0, 1.0, 0.0);
	vMatrix.rotate(rotation);

	//QMatrix4x4 mMatrix;
	//mMatrix.setToIdentity();

	//texture->bind();

	shaderProgram.bind();
	shaderProgram.setUniformValue("u_projectionMatrix", pMatrix);
	//shaderProgram.setUniformValue("u_modelMatrix", mMatrix);
	shaderProgram.setUniformValue("u_viewMatrix", vMatrix);
	//shaderProgram.setUniformValue("u_texture", 0);
	shaderProgram.setUniformValue("u_lightPosition", QVector4D(0.0, 0.0, 0.0, 1.0));
	shaderProgram.setUniformValue("u_lightPower", 5.0f);

	for (int i = 0; i < objects.size(); i++) {
		objects[i]->draw(&shaderProgram, context()->functions());
	}

	//arrayBuffer.bind();

	//int offset = 0;

	//int verLoc = shaderProgram.attributeLocation("a_position");
	//shaderProgram.enableAttributeArray(verLoc);
	//shaderProgram.setAttributeBuffer(verLoc, GL_FLOAT, offset, 3, sizeof(Vertex));

	//offset += sizeof(QVector3D);

	//int texLoc = shaderProgram.attributeLocation("a_texcoord");
	//shaderProgram.enableAttributeArray(texLoc);
	//shaderProgram.setAttributeBuffer(texLoc, GL_FLOAT, offset, 2, sizeof(Vertex));

	//offset += sizeof(QVector2D);

	//int normLoc = shaderProgram.attributeLocation("a_normal");
	//shaderProgram.enableAttributeArray(normLoc);
	//shaderProgram.setAttributeBuffer(normLoc, GL_FLOAT, offset, 2, sizeof(Vertex));

	//indexBuffer.bind();

	//glDrawElements(GL_TRIANGLES, indexBuffer.size(), GL_UNSIGNED_INT, 0);

}

void Widget::mousePressEvent(QMouseEvent* event) {
	if (event->buttons() == Qt::LeftButton)
		mousePosition = QVector2D(event->localPos());
	event->accept();
}

void Widget::mouseMoveEvent(QMouseEvent* event) {
	if (event->buttons() != Qt::LeftButton) return;

	QVector2D diff = QVector2D(event->localPos()) - mousePosition;
	mousePosition = QVector2D(event->localPos());

	float angle = diff.length();

	QVector3D axis = QVector3D(diff.y(), diff.x(), 0.0);

	rotation = QQuaternion::fromAxisAndAngle(axis, angle) * rotation;

	update();
}

void Widget::initShaders() {
	if (!shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, "./VertexShader.vsh")) {
		QString log = shaderProgram.log();
		close();
	}
	if (!shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, "./FragmentShader.fsh")) {
		QString log = shaderProgram.log();
		close();
	}
	if (!shaderProgram.link()) {
		QString log = shaderProgram.log();
		close();
	}
}

void Widget::initCube(float width) {
	QVector<Vertex> vertices;
	vertices <<
		Vertex(QVector3D(-width, width, width), QVector2D(0.0, 1.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(-width, -width, width), QVector2D(0.0, 0.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(width, width, width), QVector2D(1.0, 1.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(1.0, 0.0), QVector3D(0.0, 0.0, 1.0)) <<

		Vertex(QVector3D(width, width, width), QVector2D(0.0, 1.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(0.0, 0.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, width, -width), QVector2D(1.0, 1.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(1.0, 0.0), QVector3D(1.0, 0.0, 0.0)) <<

		Vertex(QVector3D(width, width, width), QVector2D(0.0, 1.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(width, width, -width), QVector2D(0.0, 0.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(-width, width, width), QVector2D(1.0, 1.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(1.0, 0.0), QVector3D(0.0, 1.0, 0.0)) <<

		Vertex(QVector3D(width, width, -width), QVector2D(0.0, 1.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(0.0, 0.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(1.0, 1.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(1.0, 0.0), QVector3D(0.0, 0.0, -1.0)) <<

		Vertex(QVector3D(-width, width, width), QVector2D(0.0, 1.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(0.0, 0.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, width), QVector2D(1.0, 1.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(1.0, 0.0), QVector3D(-1.0, 0.0, 0.0)) <<

		Vertex(QVector3D(-width, -width, width), QVector2D(0.0, 1.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(0.0, 0.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(1.0, 1.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(1.0, 0.0), QVector3D(0.0, -1.0, 0.0));

	QVector<GLuint> indices;
	indices << 0 << 1 << 2 << 2 << 1 << 3;
	for (int i = 0; i < 24; i += 4)
		indices << i + 0 << i + 1 << i + 2 << i + 2 << i + 1 << i + 3;

	objects << new SimpleObject3D(vertices, indices, QImage("./cube.jpg"));

	//arrayBuffer.create();
	//arrayBuffer.bind();
	//arrayBuffer.allocate(vertices.constData(), vertices.size() * sizeof(Vertex));
	//arrayBuffer.release();

	//indexBuffer.create();
	//indexBuffer.bind();
	//indexBuffer.allocate(indices.constData(), indices.size() * sizeof(GLuint));
	//indexBuffer.release();

	//texture = new QOpenGLTexture(QImage("./cube.jpg").mirrored());

	//// Set nearest filtering mode for texture minification
	//texture->setMinificationFilter(QOpenGLTexture::Linear);

	//// Set bilinear filtering mode for texture magnification
	//texture->setMagnificationFilter(QOpenGLTexture::Linear);

	//// Wrap texture coordinates by repreating
	//// f. ex. texture coordinate (1.1, 1.2) is same as 0.1, 0.2;
	//texture->setWrapMode(QOpenGLTexture::Repeat);
}
