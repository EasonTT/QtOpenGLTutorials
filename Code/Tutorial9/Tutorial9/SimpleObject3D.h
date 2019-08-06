#pragma once
#include <qopenglbuffer.h>
#include <qmatrix4x4.h>
#include <qvector2d.h>
#include <qopengltexture.h>
#include <qopenglfunctions.h>
#include <qopenglshaderprogram.h>
#include "Transformational.h"
#include "Material.h"

struct Vertex {
	Vertex() {};
	Vertex(QVector3D position, QVector2D texCoord, QVector3D normal) :
		position(position), texCoord(texCoord), normal(normal) {
	};
	QVector3D position;
	QVector2D texCoord;
	QVector3D normal;
};

class SimpleObject3D : public Transformational {
public:
	SimpleObject3D();
	SimpleObject3D(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, Material* material);
	~SimpleObject3D();
	void init(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, Material* material);
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);
	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions);

private:
	QOpenGLBuffer vertexBuffer;
	QOpenGLBuffer indexBuffer;
	QOpenGLTexture* texture;

	QQuaternion r;
	QVector3D t;
	float s;
	QMatrix4x4 g;

	Material* material;
};

