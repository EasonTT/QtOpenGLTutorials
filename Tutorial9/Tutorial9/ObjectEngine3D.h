#pragma once
#include "SimpleObject3D.h"
#include "MaterialLibrary.h"


class ObjectEngine3D : public Transformational {
public:
	ObjectEngine3D();
	~ObjectEngine3D();
	void loadObjectFromFile(const QString& fileName);
	void addObject(SimpleObject3D* object);
	SimpleObject3D* getObject(int index);

	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions);
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);

private:
	QVector<SimpleObject3D*> objects;
	MaterialLibrary materials;
};

