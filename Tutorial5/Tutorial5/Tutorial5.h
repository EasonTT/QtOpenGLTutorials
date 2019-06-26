#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tutorial5.h"

class Tutorial5 : public QMainWindow
{
	Q_OBJECT

public:
	Tutorial5(QWidget *parent = Q_NULLPTR);

private:
	Ui::Tutorial5Class ui;
};
