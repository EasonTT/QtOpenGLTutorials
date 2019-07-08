#pragma once
#include <qopenglwidget.h>
#include <qmatrix4x4.h>
#include <qopenglshaderprogram.h>
#include <qopengltexture.h>
#include <qopenglbuffer.h>
#include <QMouseEvent>
#include "SimpleObject3D.h"
#include "Group3D.h"
#include <qopenglcontext.h>
#include <qbasictimer.h>
#include <QtMath>
#include "Camera3D.h"
#include <QKeyEvent>
#include "Skybox.h"
#include <qstringlist.h>
#include <qstring.h>

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
	void timerEvent(QTimerEvent* event);
	void keyPressEvent(QKeyEvent* event);

	void initShaders();
	void initCube(float width);
	void loadObj(const QString &path);

private:
	QMatrix4x4 pMatrix;
	QOpenGLShaderProgram objectShader;
	QOpenGLShaderProgram skyboxShader;
	QVector2D mousePosition;

	QVector<SimpleObject3D*> objects;
	QVector<Group3D*> groups;
	QVector<Transformational*> transformObjects;

	QBasicTimer timer;

	float angleObject;
	float angleGroup1;
	float angleGroup2;
	float angleMain;

	Camera3D* camera;
	Skybox* skybox;
};

