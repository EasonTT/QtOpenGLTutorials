#pragma once
#include <qstring>
#include <qvector3d.h>
#include <qimage.h>

class Material {
public:
	Material();
	~Material();

	void setMaterialName(const QString& materialName);
	const QString& getMaterialName() const;
	void setDiffuseColor(const QVector3D& diffuseColor);
	const QVector3D& getDiffuseColor() const;
	void setAmbienceColor(const QVector3D& ambienceColor);
	const QVector3D& getAmbienceColor() const;
	void setSpecularColor(const QVector3D& specularColor);
	const QVector3D& getSpecularColor() const;
	void setShinnes(const qreal& shinnes);
	const qreal getShinnes() const;
	void setDiffuseMap(const QString& fileName);
	void setDiffuseMap(const QImage& image);
	const QImage& getDiffuseMap() const;

private:
	QString materialName;
	QVector3D diffuseColor;
	QVector3D ambienceColor;
	QVector3D specularColor;
	qreal shinnes;
	QImage diffuseMap;
};

