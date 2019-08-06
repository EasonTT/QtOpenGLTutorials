#include "Material.h"

/*
Description:
	This function is a constructor;
Input:
	@ void parameter: void;
*/
Material::Material() {
}

/*
Description:
	This function is a destructor;
Input:
	@ void patameter: void;
*/
Material::~Material() {
}

/*
Description:
	This function is used to set material name;
Input:
	@ const QString & materialName: material name;
Output:
	@ void returnValue: void;
*/
void Material::setMaterialName(const QString& materialName) {
	this->materialName = materialName;
}

/*
Description:
	This function is used to get material name;
Input:
	@ void parameter: void;
Output:
	@ const QString & returnValue: material name;
*/
const QString& Material::getMaterialName() const {
	return materialName;
}

/*
Description:
	This function is used to set diffuse color of the material;
Input:
	@ const QVector3D & diffuseColor: diffuse color;
Output:
	@ void returnValue: void;
*/
void Material::setDiffuseColor(const QVector3D& diffuseColor) {
	this->diffuseColor = diffuseColor;
}

/*
Description:
	This function is used to get diffuse color of the material;
Input:
	@ void parameter: void;
Output:
	@ const QVector3D & returnValue: diffuse color;
*/
const QVector3D& Material::getDiffuseColor() const {
	return diffuseColor;
}

/*
Description:
	This function is used to set ambient color for the material;
Input:
	@ const QVector3D & ambientColor: ambient color;
Output:
	@ void returnValue: void;
*/
void Material::setAmbienceColor(const QVector3D& ambienceColor) {
	this->ambienceColor = ambienceColor;
}

/*
Description:
	This function is used to get ambient color of the material;
Input:
	@ void parameter: void;
Output:
	@ const QVector3D & returnValue: ambient color;
*/
const QVector3D& Material::getAmbienceColor() const {
	return ambienceColor;
}

/*
Description:
	This function is used to set specular color for the material;
Input:
	@ const QVector3D & specularColor: specular color;
Output:
	@ void returnValue: void;
*/
void Material::setSpecularColor(const QVector3D& specularColor) {
	this->specularColor = specularColor;
}

/*
Description:
	This function is used to get specular color of the material;
Input:
	@ void parameter: void;
Output:
	@ const QVector3D & returnValue: specular color;
*/
const QVector3D& Material::getSpecularColor() const {
	return specularColor;
}

/*
Description:
	This function is used to set shinnes for the material;
Input:
	@ const QVector3D & shinnes: shinnes;
Output:
	@ void returnValue: void;
*/
void Material::setShinnes(const qreal& shinnes) {
	this->shinnes = shinnes;
}

/*
Description:
	This function is used to get shinnes of the material;
Input:
	@ void parameter: void;
Output:
	@ const QVector3D & returnValue: shinnes;
*/
const float Material::getShinnes() const {
	return shinnes;
}

/*
Description:
	This function is used to set texture for material using an image from path;
Input:
	@ const QString & fileName: a given texture image path;
Output:
	@ void returnValue: void;
*/
void Material::setDiffuseMap(const QString& fileName) {
	this->diffuseMap = QImage(fileName);
	this->usingDiffuseMap = true;
}

/*
Description:
	This function is used to set texture for material using an image;
Input:
	@ const QImage & image: a given texture image;
Output:
	@ void returnValue: void;
*/
void Material::setDiffuseMap(const QImage& image) {
	diffuseMap = image;
	this->usingDiffuseMap = true;
}

/*
Description:
	This function is used to get diffuse map of the material;
Input:
	@ void parameter: void;
Output:
	@ const QImage & returnValue: a diffuse map;
*/
const QImage& Material::getDiffuseMap() const {
	return diffuseMap;
}

/*
Description:
	This function is used to get if diffuse map is used to the material;
Input:
	@ void parameter: void;
Output:
	@ const bool returnValue: if diffuse map is used;
*/
const bool Material::isUsingDiffuseMap() const {
	return usingDiffuseMap;
}
