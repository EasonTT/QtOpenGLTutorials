#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tutorial7.h"

class Tutorial7 : public QMainWindow
{
	Q_OBJECT

public:
	Tutorial7(QWidget *parent = Q_NULLPTR);

private:
	Ui::Tutorial7Class ui;
};
