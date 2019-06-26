#include "Camera3D.h"

Camera3D::Camera3D() {
	this->s = 1.0;
	g.setToIdentity();
}

void Camera3D::rotate(const QQuaternion& r) {
	this->r = r * this->r;
}

void Camera3D::translate(const QVector3D& t) {
	this->t += t;
}

void Camera3D::scale(const float& s) {
	this->s *= s;
}

void Camera3D::setGlobalTransform(const QMatrix4x4& g) {
	this->g = g;
}

void Camera3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {

	if (functions != 0) return;

	QMatrix4x4 viewMatrix;
	viewMatrix.setToIdentity();
	viewMatrix.translate(t);
	viewMatrix.rotate(r);
	viewMatrix.scale(s);
	viewMatrix = g * viewMatrix;

	shaderProgram->setUniformValue("u_viewMatrix", viewMatrix);
}
