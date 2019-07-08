#include "MaterialLibrary.h"

MaterialLibrary::MaterialLibrary() {
}

void MaterialLibrary::addMaterial(Material* material) {

	if (!material) return;

	for (int i = 0; i < materials.size(); i++) {
		if (materials[i] == material) {
			return;
		}
	}

	materials.append(material);
}

Material* MaterialLibrary::getMaterial(int index) {
	if (index < materials.size()) {
		return materials[index];
	}
	else {
		return 0;
	}
}

Material* MaterialLibrary::getMaterial(const QString& materialName) {
	for (int i = 0; i < materials.size(); i++) {
		if (materials[i]->getMaterialName() == materialName) {
			return materials[i];
		}
	}
	return 0;
}

int MaterialLibrary::getCount() {
	return materials.size();
}

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
