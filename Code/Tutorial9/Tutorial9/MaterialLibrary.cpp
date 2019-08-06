#include "MaterialLibrary.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
MaterialLibrary::MaterialLibrary() {
}

/*
Description:
	This function is used to add material to the material list;
Input:
	@ Material * mateiral: a given material;
Output:
	@ void returnValue: void;
*/
void MaterialLibrary::addMaterial(Material* material) {

	if (!material) return;

	for (int i = 0; i < materials.size(); i++) {
		if (materials[i] == material) {
			return;
		}
	}

	materials.append(material);
}

/*
Description:
	This function is used to get material from the material list by its index;
Input:
	@ const int index: a index refer to the material;
Output:
	@ Material * returnValue: a material;
*/
Material* MaterialLibrary::getMaterial(int index) {
	if (index < materials.size()) {
		return materials[index];
	}
	else {
		return 0;
	}
}

/*
Description:
	This function is used to get material from the material list by its name;
Input:
	@ const QString & materialName: a name refer to the material;
Output:
	@ Material * returnValue: a material;
*/
Material* MaterialLibrary::getMaterial(const QString& materialName) {
	for (int i = 0; i < materials.size(); i++) {
		if (materials[i]->getMaterialName() == materialName) {
			return materials[i];
		}
	}
	return 0;
}

/*
Description:
	This function is used to get total amount of materials in the material library;
Input:
	@ void parameter;
Output:
	@ int returnValue: the total amount of materials;
*/
int MaterialLibrary::getCount() {
	return materials.size();
}

/*
Description:
	This function is used to load .mtl file froma given file path, the .mtl file should include
	material name [newmtl], ambience color [Ka], diffuse color [Kd], specular color [Ks], shinnes [Ns], diffuse map file name [map_Kd], etc.
Input:
	@ const QString & fileName: the path refer to the .mtl file
Output:
	@ void returnValue: void;
*/
void MaterialLibrary::loadMaterialFromFile(const QString& fileName) {
	QFile materialFile(fileName);

	if (!materialFile.open(QIODevice::ReadOnly)) {
		return;
	}

	for (int i = 0; i < materials.size(); i++)
		delete materials[i];
	materials.clear();

	QFileInfo fileInfo(fileName);
	QTextStream inputStream(&materialFile);

	Material* material = 0;

	while (!inputStream.atEnd()) {
		QString line = inputStream.readLine();
		QStringList list = line.split(" ");
		if (list[0] == "newmtl") {
			addMaterial(material);
			material = new Material();
			material->setMaterialName(list[1]);
		}
		else if (list[0] == "Ns") {
			material->setShinnes(list[1].toFloat());
		}
		else if (list[0] == "Ka") {
			material->setAmbienceColor(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
		}
		else if (list[0] == "Kd") {
			material->setDiffuseColor(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
		}
		else if (list[0] == "Ks") {
			material->setSpecularColor(QVector3D(list[1].toFloat(), list[2].toFloat(), list[3].toFloat()));
		}
		else if (list[0] == "map_Kd") {
			material->setDiffuseMap(QString("%1/%2").arg(fileInfo.absolutePath()).arg(list[1]));
		}
	}

	addMaterial(material);
}
