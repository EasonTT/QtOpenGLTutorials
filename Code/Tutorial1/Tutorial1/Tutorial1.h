#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tutorial1.h"

class Tutorial1 : public QMainWindow
{
	Q_OBJECT

public:
	Tutorial1(QWidget *parent = Q_NULLPTR);

private:
	Ui::Tutorial1Class ui;
};
