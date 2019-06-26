#pragma once
#include <qquaternion.h>
#include <qvector3d.h>
#include <qopenglshaderprogram.h>
#include <qopenglfunctions.h>

class Transformational {
public:
	virtual void rotate(const QQuaternion& r) = 0;
	virtual void translate(const QVector3D& t) = 0;
	virtual void scale(const float& s) = 0;
	virtual void setGlobalTransform(const QMatrix4x4& g) = 0;
	virtual void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) = 0;
};

