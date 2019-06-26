#pragma once
#include <qopenglwidget.h>
#include <qmatrix4x4.h>
#include <qopenglshaderprogram.h>
#include <qopengltexture.h>
#include <qopenglbuffer.h>
#include <QMouseEvent>
#include "SimpleObject3D.h"
#include <qopenglcontext.h>

class Widget :
	public QOpenGLWidget {
public:
	Widget(QWidget* parent = 0);
	~Widget();

protected:
	void initializeGL();
	void resizeGL(int width, int height);
	void paintGL();

	void mousePressEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	void wheelEvent(QWheelEvent* event);

	void initShaders();
	void initCube(float width);

private:
	QMatrix4x4 pMatrix;
	QOpenGLShaderProgram shaderProgram;

	QVector2D mousePosition;
	QQuaternion rotation;
	float z;

	QVector<SimpleObject3D*> objects;
};

