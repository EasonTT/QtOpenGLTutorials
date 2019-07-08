#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tutorial6.h"

class Tutorial6 : public QMainWindow
{
	Q_OBJECT

public:
	Tutorial6(QWidget *parent = Q_NULLPTR);

private:
	Ui::Tutorial6Class ui;
};
