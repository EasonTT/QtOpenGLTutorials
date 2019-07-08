#pragma once
#include "Transformational.h"
#include "SimpleObject3D.h"

class Skybox : public Transformational {
public:
	Skybox(float width, const QImage& texture);
	~Skybox();
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);
	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions);

private:
	SimpleObject3D* box;
};

