#include "Material.h"

Material::Material() {
}

Material::~Material() {
}

void Material::setMaterialName(const QString& materialName) {
	this->materialName = materialName;
}

const QString& Material::getMaterialName() const {
	// TODO: insert return statement here
	return materialName;
}

void Material::setDiffuseColor(const QVector3D& diffuseColor) {
	this->diffuseColor = diffuseColor;
}

const QVector3D& Material::getDiffuseColor() const {
	// TODO: insert return statement here
	return diffuseColor;
}

void Material::setAmbienceColor(const QVector3D& ambienceColor) {
	this->ambienceColor = ambienceColor;
}

const QVector3D& Material::getAmbienceColor() const {
	// TODO: insert return statement here
	return ambienceColor;
}

void Material::setSpecularColor(const QVector3D& specularColor) {
	this->specularColor = specularColor;
}

const QVector3D& Material::getSpecularColor() const {
	// TODO: insert return statement here
	return specularColor;
}

void Material::setShinnes(const qreal& shinnes) {
	this->shinnes = shinnes;
}

const float Material::getShinnes() const {
	return shinnes;
}

void Material::setDiffuseMap(const QString& fileName) {
	this->diffuseMap = QImage(fileName);
	this->usingDiffuseMap = true;
}

void Material::setDiffuseMap(const QImage& image) {
	diffuseMap = image;
	this->usingDiffuseMap = true;
}

const QImage& Material::getDiffuseMap() const {
	// TODO: insert return statement here
	return diffuseMap;
}

const bool Material::isUsingDiffuseMap() const {
	return usingDiffuseMap;
}
