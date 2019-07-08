#include "Group3D.h"

Group3D::Group3D() {
	this->s = 1.0;
}

void Group3D::rotate(const QQuaternion& r) {
	this->r = r * this->r;

	QMatrix4x4 localMatrix;
	localMatrix.setToIdentity();
	localMatrix.translate(t);
	localMatrix.rotate(r);
	localMatrix.scale(s);
	localMatrix = g * localMatrix;

	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(localMatrix);
}

void Group3D::translate(const QVector3D& t) {
	this->t += t;

	QMatrix4x4 localMatrix;
	localMatrix.setToIdentity();
	localMatrix.translate(t);
	localMatrix.rotate(r);
	localMatrix.scale(s);
	localMatrix = g * localMatrix;

	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(localMatrix);
}

void Group3D::scale(const float& s) {
	this->s *= s;

	QMatrix4x4 localMatrix;
	localMatrix.setToIdentity();
	localMatrix.translate(t);
	localMatrix.rotate(r);
	localMatrix.scale(s);
	localMatrix = g * localMatrix;

	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(localMatrix);
}

void Group3D::setGlobalTransform(const QMatrix4x4& g) {
	this->g = g;

	QMatrix4x4 localMatrix;
	localMatrix.setToIdentity();
	localMatrix.translate(t);
	localMatrix.rotate(r);
	localMatrix.scale(s);
	localMatrix = g * localMatrix;

	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(localMatrix);
}

void Group3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->draw(shaderProgram, functions);
	}
}

void Group3D::addObject(Transformational* object) {
	objects.append(object);

	QMatrix4x4 localMatrix;
	localMatrix.setToIdentity();
	localMatrix.translate(t);
	localMatrix.rotate(r);
	localMatrix.scale(s);
	localMatrix = g * localMatrix;

	objects[objects.size() - 1]->setGlobalTransform(localMatrix);
}

void Group3D::delObject(Transformational* object) {
	objects.removeAll(object);
}

void Group3D::delObject(const int& index) {
	objects.remove(index);
}
