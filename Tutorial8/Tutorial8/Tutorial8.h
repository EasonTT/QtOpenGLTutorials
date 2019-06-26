#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Tutorial8.h"

class Tutorial8 : public QMainWindow
{
	Q_OBJECT

public:
	Tutorial8(QWidget *parent = Q_NULLPTR);

private:
	Ui::Tutorial8Class ui;
};
