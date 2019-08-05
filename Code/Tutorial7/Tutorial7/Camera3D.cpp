#include "Camera3D.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
Camera3D::Camera3D() {
	this->s = 1.0;
	g.setToIdentity();
}

/*
Description:
	This function is used to rotate the camera;
Input:
	@ const QQuaternion& r: a quaternion (scalar, x position, y position, and z position) for rotation;
Output:
	@ void returnValue: void;
*/
void Camera3D::rotate(const QQuaternion& r) {
	this->r = r * this->r;

	viewMatrix.setToIdentity();
	viewMatrix.translate(t);
	viewMatrix.rotate(r);
	viewMatrix.scale(s);
	viewMatrix = viewMatrix * g.inverted();
}

/*
Description:
	This function is used to translate the camera;
Input:
	@ const QVector3D& t: a translation vector;
Output:
	@ void returnValue: void;
*/
void Camera3D::translate(const QVector3D& t) {
	this->t += t;

	viewMatrix.setToIdentity();
	viewMatrix.translate(t);
	viewMatrix.rotate(r);
	viewMatrix.scale(s);
	viewMatrix = viewMatrix * g.inverted();
}

/*
Description:
	This function is used to scale the camera;
Input:
	@ const float& s: a scalar;
Output:
	@ void returnValue: void;
*/
void Camera3D::scale(const float& s) {
	this->s *= s;

	viewMatrix.setToIdentity();
	viewMatrix.translate(t);
	viewMatrix.rotate(r);
	viewMatrix.scale(s);
	viewMatrix = viewMatrix * g.inverted();
}

/*
Description:
	This function is used to set the global transform for the camera;
Input:
	@ const QMatrix4x4& g: a global transformation;
Output:
	@ void returnValue: void;
*/
void Camera3D::setGlobalTransform(const QMatrix4x4& g) {
	this->g = g;

	viewMatrix.setToIdentity();
	viewMatrix.translate(t);
	viewMatrix.rotate(r);
	viewMatrix.scale(s);
	viewMatrix = viewMatrix * g.inverted();
}

/*
Description:
	This function is used to set parameters for the vertex shader, fragment shader and etc.;
Input:
	@ QOpenGLShaderProgram* shaderProgram: the shader program used for loading shaders and passing parameters;
	@ QOpenGLFunctions* functions: the OpenGL functions used to drawing elements;
Output:
	@ void returnValue: void;
*/
void Camera3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	if (functions != 0) return;

	shaderProgram->setUniformValue("u_viewMatrix", viewMatrix);
}
