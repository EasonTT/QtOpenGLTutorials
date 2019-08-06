#include "Skybox.h"

/*
Description:
	This function is a constructor;
Input:
	@ const float width: width of the skybox, where the default value is 70.0f;
	@ const QImage &texture: the texture of the skybox;
*/
Skybox::Skybox(float width, const QImage& texture) {
	QVector<Vertex> vertices;
	vertices <<
		Vertex(QVector3D(-width, width, width), QVector2D(4.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(-width, -width, width), QVector2D(4.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(width, width, width), QVector2D(3.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(3.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, -1.0)) <<

		Vertex(QVector3D(width, width, width), QVector2D(3.0 / 4.0, 2.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(3.0 / 4.0, 1.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, width, -width), QVector2D(2.0 / 4.0, 2.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(2.0 / 4.0, 1.0 / 3.0), QVector3D(-1.0, 0.0, 0.0)) <<

		Vertex(QVector3D(width, width, width), QVector2D(2.0 / 4.0, 3.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(width, width, -width), QVector2D(2.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(-width, width, width), QVector2D(1.0 / 4.0, 3.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(1.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, -1.0, 0.0)) <<

		Vertex(QVector3D(width, width, -width), QVector2D(2.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(2.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(1.0 / 4.0, 2.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(1.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 0.0, 1.0)) <<

		Vertex(QVector3D(-width, width, width), QVector2D(0.0 / 4.0, 2.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(1.0 / 4.0, 2.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, width), QVector2D(0.0 / 4.0, 1.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(1.0 / 4.0, 1.0 / 3.0), QVector3D(1.0, 0.0, 0.0)) <<

		Vertex(QVector3D(-width, -width, width), QVector2D(1.0 / 4.0, 0.0 / 3.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(1.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(2.0 / 4.0, 0.0 / 3.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(2.0 / 4.0, 1.0 / 3.0), QVector3D(0.0, 1.0, 0.0));

	QVector<GLuint> indices;
	indices << 0 << 1 << 2 << 2 << 1 << 3;
	for (int i = 0; i < 24; i += 4)
		indices <<
		i + 0 <<
		i + 2 <<
		i + 1 <<
		i + 2 <<
		i + 3 <<
		i + 1;

	box = new SimpleObject3D(vertices, indices, texture);
}

/*
Description:
	This function is a destructor;
Input:
	@ void paramter: void;
*/
Skybox::~Skybox() {
	delete box;
}

/*
Description:
	This function is used to rotate the skybox, which calls Object3D::rotate(const QQuaternion&) for object rotation;
Input:
	@ const QQuaternion& r: a quaternion (scalar, x position, y position, and z position) for rotation;
Output:
	@ void returnValue: void;
*/
void Skybox::rotate(const QQuaternion& r) {
	(void)r;
}

/*
Description:
	This function is used to translate the skybox, which calls Object3D::translate(const QVector3D&) for object translation;
Input:
	@ const QVector3D& t: a translation vector;
Output:
	@ void returnValue: void;
*/
void Skybox::translate(const QVector3D& t) {
	(void)t;
}

/*
Description:
	This function is used to scale the skybox, which calls Object3D::scale(const float&) for object scaling;
Input:
	@ const float& s: a scalar;
Output:
	@ void returnValue: void;
*/
void Skybox::scale(const float& s) {
	(void)s;
}

/*
Description:
	This function is used to set the global transform for the skybox, which calls Object3D::setGlobalTransform(const QMatrix4x4&) for setting global transform;
Input:
	@ const QMatrix4x4& g: a global transformation;
Output:
	@ void returnValue: void;
*/
void Skybox::setGlobalTransform(const QMatrix4x4& g) {
	(void)& g;
}

/*
Description:
	This function is used to draw the skybox, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
Input:
	@ QOpenGLShaderProgram* shaderProgram: the shader program used for loading shaders and passing parameters;
	@ QOpenGLFunctions* functions: the OpenGL functions used to drawing elements;
Output:
	@ void returnValue: void;
*/
void Skybox::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	box->draw(shaderProgram, functions);
}
