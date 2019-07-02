#pragma once
#include "Transformational.h"
#include "SimpleObject3D.h"

class Group3D : public Transformational {
public:
	Group3D();
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);
	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions);

	void addObject(Transformational* object);
	void delObject(Transformational* object);
	void delObject(const int& index);

private:
	QQuaternion r;
	QVector3D t;
	float s;
	QMatrix4x4 g;

	QVector<Transformational*> objects;
};

