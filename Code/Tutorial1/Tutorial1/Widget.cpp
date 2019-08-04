#include "Widget.h"

/*
Description:
	This function is a constructor;
Input:
	@ QWidget* parent:
*/
Widget::Widget(QWidget* parent) :
	QOpenGLWidget(parent), texture(0), indexBuffer(QOpenGLBuffer::IndexBuffer) {
}

/*
Description:
	This function is a destructor;
Input:
	@ void patameter: void;
*/
Widget::~Widget() {
}

/*
Description:
	This function is used to initialize OpenGL state machine, and initialize shaders ,objects and etc.;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void Widget::initializeGL() {
	// clear the screen with black
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// initialize shaders
	initShaders();
	initCube(1.0);
}

/*
Description:
	This function is used to deal with resive event;
Input:
	@ int width: window width after resize event;
	@ int height: window height after resize event;
Output:
	@ void returnValue: void;
*/
void Widget::resizeGL(int width, int height) {
	float aspect = width / (float)height;

	pMatrix.setToIdentity();
	pMatrix.perspective(45, aspect, 0.1f, 10.0f);
}

/*
Description:
	This function is used to set parameters for the vertex shader, fragment shader and etc. and draw other objects;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void Widget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	QMatrix4x4 mMatrix;
	mMatrix.setToIdentity();
	mMatrix.translate(0.0, 0.0, -5.0);
	mMatrix.rotate(30, 1.0, 0.0, 0.0);
	mMatrix.rotate(30, 0.0, 1.0, 0.0);

	texture->bind();

	shaderProgram.bind();
	shaderProgram.setUniformValue("qt_ModelViewProjectionMatrix", pMatrix * mMatrix);
	shaderProgram.setUniformValue("qt_Texture0", 0);

	arrayBuffer.bind();

	int offset = 0;

	int verLoc = shaderProgram.attributeLocation("qt_Vertex");
	shaderProgram.enableAttributeArray(verLoc);
	shaderProgram.setAttributeBuffer(verLoc, GL_FLOAT, offset, 3, sizeof(Vertex));

	offset += sizeof(QVector3D);

	int texLoc = shaderProgram.attributeLocation("qt_MultiTexCoord0");
	shaderProgram.enableAttributeArray(texLoc);
	shaderProgram.setAttributeBuffer(texLoc, GL_FLOAT, offset, 2, sizeof(Vertex));

	indexBuffer.bind();

	glDrawElements(GL_TRIANGLES, indexBuffer.size(), GL_UNSIGNED_INT, 0);

}

/*
Description:
	This function is used to initialize shaders and objects;
Input:
	@ void parameter: void;
Output:
	@ void returnValue: void;
*/
void Widget::initShaders() {
	if (!shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, "./VertexShader.vsh"))
		close();
	if (!shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, "./FragmentShader.fsh"))
		close();
	if (!shaderProgram.link())
		close();
}

/*
Description:
	This function is used to load graphics data for a cube, including vertex data and index data;
Input:
	@ int width: the width of the cube;
Output:
	@ void returnValue: void;
*/
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

	arrayBuffer.create();
	arrayBuffer.bind();
	arrayBuffer.allocate(vertices.constData(), vertices.size() * sizeof(Vertex));
	arrayBuffer.release();

	indexBuffer.create();
	indexBuffer.bind();
	indexBuffer.allocate(indices.constData(), indices.size() * sizeof(GLuint));
	indexBuffer.release();

	texture = new QOpenGLTexture(QImage("./cube.jpg").mirrored());

	// Set nearest filtering mode for texture minification
	texture->setMinificationFilter(QOpenGLTexture::Linear);

	// Set bilinear filtering mode for texture magnification
	texture->setMagnificationFilter(QOpenGLTexture::Linear);
	
	// Wrap texture coordinates by repreating
	// f. ex. texture coordinate (1.1, 1.2) is same as 0.1, 0.2;
	texture->setWrapMode(QOpenGLTexture::Repeat);
}
