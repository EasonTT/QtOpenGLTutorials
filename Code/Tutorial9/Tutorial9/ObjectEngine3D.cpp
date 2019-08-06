#include "ObjectEngine3D.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
ObjectEngine3D::ObjectEngine3D() {
}

/*
Description:
	This function is a destructor;
Input:
	@ void patameter: void;
*/
ObjectEngine3D::~ObjectEngine3D() {
}

/*
Description:
	This function is used to load .obj file from a given filepath, the .obj file should include
	vertex coordinations [v], texture coordinations [vt], normals [vn], vertex indices of a given face [f], material library file name [mtllib], material name [usemtl].
Input:
	@ const QString & filePath: the path refer to the .obj file
Output:
	@ void returnValue: void;
*/
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
			if (object) object->init(vertices, indices, materials.getMaterial(materialName));
			materialName = list[1];
			addObject(object);
			object = new SimpleObject3D;
		}
	}

	if (object) object->init(vertices, indices, materials.getMaterial(materialName));
	addObject(object);
	
	objFile.close();
}

/*
Description:
	This function is used to append an object to the end of the object list;
Input:
	@ Object3D * object: the object;
Output:
	@ void returnValue: void;
*/
void ObjectEngine3D::addObject(SimpleObject3D* object) {
	if (!object) return;
	for (int i = 0; i < objects.size(); i++) {
		if (objects[i] == object)
			return;
	}
	objects.append(object);
}

/*
Description:
	This function is used to get an object from object list by its index;
Input:
	@ const int index: index refer to the object;
Output:
	@ const int returnValue: a pointer to an object;
*/
SimpleObject3D* ObjectEngine3D::getObject(int index) {
	if (index < objects.size()) {
		return objects[index];
	}
	else {
		return 0;
	}
}

/*
Description:
	This function is used to rotate objects defined in the object engine, which calls Object3D::rotate(const QQuaternion&);
Input:
	@ const QQuaternion& r: a quaternion (scalar, x position, y position, and z position) for rotation;
Output:
	@ void returnValue: void;
*/
void ObjectEngine3D::rotate(const QQuaternion& r) {
	for (int i = 0; i < objects.size(); i++)
		objects[i]->rotate(r);
}

/*
Description:
	This function is used to translate objects defined in the object engine, which calls Object3D::translate(const QVector3D&);
Input:
	@ const QVector3D& t: a translation vector;
Output:
	@ void returnValue: void;
*/
void ObjectEngine3D::translate(const QVector3D& t) {
	for (int i = 0; i < objects.size(); i++)
		objects[i]->translate(t);
}

/*
Description:
	This function is used to scale objects defined in the object engine, which calls Object3D::scale(const float&);
Input:
	@ const float& s: a scalar;
Output:
	@ void returnValue: void;
*/
void ObjectEngine3D::scale(const float& s) {
	for (int i = 0; i < objects.size(); i++)
		objects[i]->scale(s);
}

/*
Description:
	This function is used to set the global transform objects defined in the object engine, which calls Object3D::setGlobalTransform(const QMatrix4x4&);
Input:
	@ const QMatrix4x4& g: a global transformation;
Output:
	@ void returnValue: void;
*/
void ObjectEngine3D::setGlobalTransform(const QMatrix4x4& g) {
	for (int i = 0; i < objects.size(); i++)
		objects[i]->setGlobalTransform(g);
}

/*
Description:
	This function is used to draw objects defined in the object engine, which calls Object3D::draw(QOpenGLShaderProgram*, QOpenGLFunctions*);
Input:
	@ QOpenGLShaderProgram* shaderProgram: the shader program used for loading shaders and passing parameters;
	@ QOpenGLFunctions* functions: the OpenGL functions used to drawing elements;
Output:
	@ void returnValue: void;
*/
void ObjectEngine3D::draw(QOpenGLShaderProgram* shaderProgram, QOpenGLFunctions* functions) {
	for (int i = 0; i < objects.size(); i++)
		objects[i]->draw(shaderProgram, functions);
}