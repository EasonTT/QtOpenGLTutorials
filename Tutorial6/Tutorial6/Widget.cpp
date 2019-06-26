#include "Widget.h"

Widget::Widget(QWidget* parent) :
	QOpenGLWidget(parent) {
	//z = -5.0;
	camera = new Camera3D;
	camera->translate(QVector3D(0.0, 0.0, -5.0));
}

Widget::~Widget() {
	delete camera;

	for (int i = 0; i < objects.size(); i++)
		delete objects[i];

	for (int i = 0; i < groups.size(); i++)
		delete groups[i];

	for (int i = 0; i < transformObjects.size(); i++)
		delete transformObjects[i];
}

void Widget::initializeGL() {
	// clear the screen with black
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	// initialize shaders
	initShaders();

	float step = 2.0f;

	groups.append(new Group3D);
	for (float x = -step; x <= step; x += step) {
		for (float y = -step; y <= step; y += step) {
			for (float z = -step; z <= step; z += step) {
				initCube(0.5f);
				objects[objects.size() - 1]->translate(QVector3D(x, y, z));
				groups[groups.size() - 1]->addObject(objects[objects.size() - 1]);
			}
		}
	}
	groups[0]->translate(QVector3D(-4.0, 0.0, 0.0));

	groups.append(new Group3D);
	for (float x = -step; x <= step; x += step) {
		for (float y = -step; y <= step; y += step) {
			for (float z = -step; z <= step; z += step) {
				initCube(0.5f);
				objects[objects.size() - 1]->translate(QVector3D(x, y, z));
				groups[groups.size() - 1]->addObject(objects[objects.size() - 1]);
			}
		}
	}
	groups[1]->translate(QVector3D(4.0, 0.0, 0.0));

	groups.append(new Group3D);
	groups[2]->addObject(groups[0]);
	groups[2]->addObject(groups[1]);

	transformObjects.append(groups[2]);

	timer.start(30, this);
}

void Widget::resizeGL(int width, int height) {
	float aspect = width / (float)height;

	pMatrix.setToIdentity();
	pMatrix.perspective(45, aspect, 0.01f, 100.0f);
}

void Widget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//QMatrix4x4 vMatrix;
	//vMatrix.setToIdentity();
	//vMatrix.translate(0.0, 0.0, z);
	//vMatrix.rotate(rotation);

	shaderProgram.bind();
	shaderProgram.setUniformValue("u_projectionMatrix", pMatrix);
	//shaderProgram.setUniformValue("u_viewMatrix", vMatrix);
	shaderProgram.setUniformValue("u_lightPosition", QVector4D(0.0, 0.0, 0.0, 1.0));
	shaderProgram.setUniformValue("u_lightPower", 5.0f);

	camera->draw(&shaderProgram);

	for (int i = 0; i < transformObjects.size(); i++) {
		transformObjects[i]->draw(&shaderProgram, context()->functions());
	}

}

void Widget::mousePressEvent(QMouseEvent* event) {
	if (event->buttons() == Qt::LeftButton)
		mousePosition = QVector2D(event->localPos());
	event->accept();
}

void Widget::mouseMoveEvent(QMouseEvent* event) {
	if (event->buttons() != Qt::LeftButton) return;

	QVector2D diff = QVector2D(event->localPos()) - mousePosition;
	mousePosition = QVector2D(event->localPos());

	float angle = diff.length();

	QVector3D axis = QVector3D(diff.y(), diff.x(), 0.0);

	//rotation = QQuaternion::fromAxisAndAngle(axis, angle) * rotation;
	camera->rotate(QQuaternion::fromAxisAndAngle(axis, angle));

	update();
}

void Widget::wheelEvent(QWheelEvent* event) {
	if (event->delta() > 0) {
		//z += 0.25;
		camera->translate(QVector3D(0.0, 0.0, 0.25));
	}
	else if (event->delta() < 0) {
		//z -= 0.25;
		camera->translate(QVector3D(0.0, 0.0, -0.25));
	}
	update();
}

void Widget::timerEvent(QTimerEvent* event) {
	for (int i = 0; i < objects.size(); i++) {
		if (i % 2 == 0) {
			objects[i]->rotate(QQuaternion::fromAxisAndAngle(1.0, 0.0, 0.0, qSin(angleObject)));
			objects[i]->rotate(QQuaternion::fromAxisAndAngle(0.0, 1.0, 0.0, qCos(angleObject)));
		}
		else {
			objects[i]->rotate(QQuaternion::fromAxisAndAngle(0.0, 1.0, 0.0, qSin(angleObject)));
			objects[i]->rotate(QQuaternion::fromAxisAndAngle(1.0, 0.0, 0.0, qCos(angleObject)));
		}
	}

	groups[0]->rotate(QQuaternion::fromAxisAndAngle(0.0, 0.0, 1.0, qSin(angleGroup1)));
	groups[0]->rotate(QQuaternion::fromAxisAndAngle(0.0, 1.0, 0.0, -qSin(angleGroup1)));

	groups[1]->rotate(QQuaternion::fromAxisAndAngle(1.0, 0.0, 0.0, qCos(angleGroup1)));
	groups[1]->rotate(QQuaternion::fromAxisAndAngle(0.0, 1.0, 0.0, -qCos(angleGroup1)));

	groups[2]->rotate(QQuaternion::fromAxisAndAngle(1.0, 0.0, 0.0, qSin(angleMain)));
	groups[2]->rotate(QQuaternion::fromAxisAndAngle(0.0, 1.0, 0.0, qCos(angleMain)));

	angleObject += M_PI / 180.0f;
	angleGroup1 += M_PI / 360.0f;
	angleGroup2 -= M_PI / 360.0f;
	angleMain += M_PI / 720.0f;

	update();
}

void Widget::initShaders() {
	if (!shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, "./VertexShader.vsh")) {
		QString log = shaderProgram.log();
		close();
	}
	if (!shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, "./FragmentShader.fsh")) {
		QString log = shaderProgram.log();
		close();
	}
	if (!shaderProgram.link()) {
		QString log = shaderProgram.log();
		close();
	}
}

void Widget::initCube(float width) {
	QVector<Vertex> vertices;
	vertices <<
		Vertex(QVector3D(-width, width, width), QVector2D(0.0, 1.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(-width, -width, width), QVector2D(0.0, 0.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(width, width, width), QVector2D(1.0, 1.0), QVector3D(0.0, 0.0, 1.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(1.0, 0.0), QVector3D(0.0, 0.0, 1.0)) <<

		Vertex(QVector3D(width, width, width), QVector2D(0.0, 1.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(0.0, 0.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, width, -width), QVector2D(1.0, 1.0), QVector3D(1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(1.0, 0.0), QVector3D(1.0, 0.0, 0.0)) <<

		Vertex(QVector3D(width, width, width), QVector2D(0.0, 1.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(width, width, -width), QVector2D(0.0, 0.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(-width, width, width), QVector2D(1.0, 1.0), QVector3D(0.0, 1.0, 0.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(1.0, 0.0), QVector3D(0.0, 1.0, 0.0)) <<

		Vertex(QVector3D(width, width, -width), QVector2D(0.0, 1.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(0.0, 0.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(1.0, 1.0), QVector3D(0.0, 0.0, -1.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(1.0, 0.0), QVector3D(0.0, 0.0, -1.0)) <<

		Vertex(QVector3D(-width, width, width), QVector2D(0.0, 1.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, width, -width), QVector2D(0.0, 0.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, width), QVector2D(1.0, 1.0), QVector3D(-1.0, 0.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(1.0, 0.0), QVector3D(-1.0, 0.0, 0.0)) <<

		Vertex(QVector3D(-width, -width, width), QVector2D(0.0, 1.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(-width, -width, -width), QVector2D(0.0, 0.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(width, -width, width), QVector2D(1.0, 1.0), QVector3D(0.0, -1.0, 0.0)) <<
		Vertex(QVector3D(width, -width, -width), QVector2D(1.0, 0.0), QVector3D(0.0, -1.0, 0.0));

	QVector<GLuint> indices;
	indices << 0 << 1 << 2 << 2 << 1 << 3;
	for (int i = 0; i < 24; i += 4)
		indices << i + 0 << i + 1 << i + 2 << i + 2 << i + 1 << i + 3;

	objects << new SimpleObject3D(vertices, indices, QImage("./cube.jpg"));
}