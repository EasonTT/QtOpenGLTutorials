#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tutorial4.h"

class Tutorial4 : public QMainWindow
{
	Q_OBJECT

public:
	Tutorial4(QWidget *parent = Q_NULLPTR);

private:
	Ui::Tutorial4Class ui;
};
