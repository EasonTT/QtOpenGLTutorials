#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tutorial9.h"

class Tutorial9 : public QMainWindow
{
	Q_OBJECT

public:
	Tutorial9(QWidget *parent = Q_NULLPTR);

private:
	Ui::Tutorial9Class ui;
};
