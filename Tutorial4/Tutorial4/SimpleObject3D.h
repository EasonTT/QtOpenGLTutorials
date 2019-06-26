#pragma once
#include <qopenglbuffer.h>
#include <qmatrix4x4.h>
#include <qvector2d.h>
#include <qopengltexture.h>
#include <qopenglfunctions.h>
#include <qopenglshaderprogram.h>
#include "Transformational.h"

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
	SimpleObject3D(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, const QImage& texture);
	~SimpleObject3D();
	void init(const QVector<Vertex>& vertices, const QVector<GLuint>& indices, const QImage& image);
	void draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions);
	void rotate(const QQuaternion& r);
	void translate(const QVector3D& t);
	void scale(const float& s);
	void setGlobalTransform(const QMatrix4x4& g);

private:
	QOpenGLBuffer vertexBuffer;
	QOpenGLBuffer indexBuffer;
	//QMatrix4x4 modelMatrix;
	QOpenGLTexture* texture;

	QQuaternion r;
	QVector3D t;
	float s;
	QMatrix4x4 g;
};

