#pragma once
#include <qopenglwidget.h>
#include <qmatrix4x4.h>
#include <qopenglshaderprogram.h>
#include <qopengltexture.h>
#include <qopenglbuffer.h>

struct Vertex {
	Vertex() {};
	Vertex(QVector3D position, QVector2D texCoord, QVector3D normal) :
		position(position), texCoord(texCoord), normal(normal) {
	};
	QVector3D position;
	QVector2D texCoord;
	QVector3D normal;
};

class Widget :
	public QOpenGLWidget {
public:
	Widget(QWidget* parent = 0);
	~Widget();

protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();

	void initShaders();
	void initCube(float width);

private:
	QMatrix4x4 pMatrix;
	QOpenGLShaderProgram shaderProgram;
	QOpenGLTexture* texture;
	QOpenGLBuffer arrayBuffer;
	QOpenGLBuffer indexBuffer;
};

