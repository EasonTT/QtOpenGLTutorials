#include "Group3D.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
Group3D::Group3D() {
	this->s = 1.0;
}

/*
Description:
	This function is used to rotate all the objects in a group, which calls Object3D::rotate(const QQuaternion&) for object rotation;
Input:
	@ const QQuaternion& r: a quaternion (scalar, x position, y position, and z position) for rotation;
Output:
	@ void returnValue: void;
*/
void Group3D::rotate(const QQuaternion& r) {
	this->r = r * this->r;
}

/*
Description:
	This function is used to translate all the objects in a group, which calls Object3D::translate(const QVector3D&) for object translation;
Input:
	@ const QVector3D& t: a translation vector;
Output:
	@ void returnValue: void;
*/
void Group3D::translate(const QVector3D& t) {
	this->t += t;
}

/*
Description:
	This function is used to scale all the objects in a group, which calls Object3D::scale(const float&) for object scaling;
Input:
	@ const float& s: a scalar;
Output:
	@ void returnValue: void;
*/
void Group3D::scale(const float& s) {
	this->s *= s;
}

/*
Description:
	This function is used to set the global transform for all the objects in a group, which calls Object3D::setGlobalTransform(const QMatrix4x4&) for setting global transform;
Input:
	@ const QMatrix4x4& g: a global transformation;
Output:
	@ void returnValue: void;
*/
void Group3D::setGlobalTransform(const QMatrix4x4& g) {
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
void Group3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	QMatrix4x4 localMatrix;
	localMatrix.setToIdentity();
	localMatrix.translate(t);
	localMatrix.rotate(r);
	localMatrix.scale(s);
	localMatrix = g * localMatrix;

	for (int i = 0; i < objects.size(); i++) {
		objects[i]->setGlobalTransform(localMatrix);
		objects[i]->draw(shaderProgram, functions);
	}
}

/*
Description:
	This function is used to add object into the group list. An initialization of its position is necessary;
Input:
	@ Transformational * object: a given object;
Output:
	@ void returnValue: void;
*/
void Group3D::addObject(Transformational* object) {
	objects.append(object);
}
