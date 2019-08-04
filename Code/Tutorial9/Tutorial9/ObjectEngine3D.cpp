#include "ObjectEngine3D.h"

ObjectEngine3D::ObjectEngine3D() {
}

ObjectEngine3D::~ObjectEngine3D() {
}

void ObjectEngine3D::loadObjectFromFile(const QString& fileName) {
	QFile objFile(fileName);
	if (!objFile.exists()) {
		return;
	}

	QVector<QVector3D> verCoords;
	QVector<QVector2D> texCoords;
	QVector<QVector3D> normals;
	QVector<Vertex> vertices;
	QVector<GLuint> indices;
	SimpleObject3D* object = 0;

	objFile.open(QIODevice::ReadOnly);
	QTextStream input(&objFile);
	QString materialName;

	while (!input.atEnd()) {
		QString line = input.readLine();
		QStringList list = line.split(" ");
		if (list[0] == "#") {

		}
		else if (list[0] == "mtllib") {
			QFileInfo info(fileName);
			materials.loadMaterialFromFile(QString("%1/%2").arg(info.absolutePath()).arg(list[1]));
		}
		else if (list[0] == "v") {
			verCoords << QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat());
		}
		else if (list[0] == "vt") {
			texCoords << QVector2D(list[1].toFloat(), list[2].toFloat());
		}
		else if (list[0] == "vn") {
			normals << QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat());
		}
		else if (list[0] == "f") {
			for (int i = 1; i <= 3; i++) {
				QStringList v = list[i].split("/");
				vertices.append(Vertex(verCoords[v[0].toLong() - 1], texCoords[v[1].toLong() - 1], normals[v[2].toLong() - 1]));
				indices.append(indices.size());
			}
		}
		else if (list[0] == "usemtl") {
			//if (object) object->init(vertices, indices, materials.getMaterial(list[1]));
			if (object) object->init(vertices, indices, materials.getMaterial(materialName));
			materialName = list[1];
			addObject(object);
			object = new SimpleObject3D;
		}
	}

	if (object) object->init(vertices, indices, materials.getMaterial(materialName));
	addObject(object);
	
	objFile.close();

	// objects.append(new SimpleObject3D(vertices, indices, QImage("./cube.jpg")));
	
}

void ObjectEngine3D::addObject(SimpleObject3D* object) {
	if (!object) return;
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i] == object)
			return;
	}
	objects.append(object);
}

SimpleObject3D* ObjectEngine3D::getObject(int index) {
	if (index < objects.size()) {
		return objects[index];
	}
	else {
		return 0;
	}
}

void ObjectEngine3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	for (int i = 0; i < objects.size(); i++)
		objects[i]->draw(shaderProgram, functions);
}

void ObjectEngine3D::rotate(const QQuaternion& r) {
	for (int i = 0; i < objects.size(); i++)
		objects[i]->rotate(r);
}

void ObjectEngine3D::translate(const QVector3D& t) {
	for (int i = 0; i < objects.size(); i++)
		objects[i]->translate(t);
}

void ObjectEngine3D::scale(const float& s) {
	for (int i = 0; i < objects.size(); i++)
		objects[i]->scale(s);
}

void ObjectEngine3D::setGlobalTransform(const QMatrix4x4& g) {
	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(g);
}
