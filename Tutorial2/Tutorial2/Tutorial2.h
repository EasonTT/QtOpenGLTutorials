#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tutorial2.h"

class Tutorial2 : public QMainWindow
{
	Q_OBJECT

public:
	Tutorial2(QWidget *parent = Q_NULLPTR);

private:
	Ui::Tutorial2Class ui;
};
