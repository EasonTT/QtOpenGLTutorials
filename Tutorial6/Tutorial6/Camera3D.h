#pragma once

#include "Transformational.h"
#include <qopenglshaderprogram.h>

class Camera3D : public Transformational {
public:
	Camera3D();
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);
	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions = 0);

private:
	QQuaternion r;
	QVector3D t;
	float s;
	QMatrix4x4 g;
};

