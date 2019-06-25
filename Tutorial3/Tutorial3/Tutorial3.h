#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tutorial3.h"

class Tutorial3 : public QMainWindow
{
	Q_OBJECT

public:
	Tutorial3(QWidget *parent = Q_NULLPTR);

private:
	Ui::Tutorial3Class ui;
};
