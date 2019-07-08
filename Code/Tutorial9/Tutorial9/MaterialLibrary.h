#pragma once

#include "Material.h"
#include <qfile.h>
#include <qtextstream.h>
#include <qfileinfo.h>

class MaterialLibrary {
public:
	MaterialLibrary();
	void addMaterial(Material* material);
	Material* getMaterial(int index);
	Material* getMaterial(const QString &materialName);
	int getCount();
	void loadMaterialFromFile(const QString& fileName);

private:
	QVector<Material*> materials;
};

