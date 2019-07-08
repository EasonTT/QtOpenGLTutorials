/********************************************************************************
** Form generated from reading UI file 'Tutorial7.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL7_H
#define UI_TUTORIAL7_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "Widget.h"

QT_BEGIN_NAMESPACE

class Ui_Tutorial7Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    Widget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tutorial7Class)
    {
        if (Tutorial7Class->objectName().isEmpty())
            Tutorial7Class->setObjectName(QString::fromUtf8("Tutorial7Class"));
        Tutorial7Class->resize(829, 580);
        centralWidget = new QWidget(Tutorial7Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openGLWidget = new Widget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        Tutorial7Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tutorial7Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 829, 26));
        Tutorial7Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tutorial7Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Tutorial7Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Tutorial7Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Tutorial7Class->setStatusBar(statusBar);

        retranslateUi(Tutorial7Class);

        QMetaObject::connectSlotsByName(Tutorial7Class);
    } // setupUi

    void retranslateUi(QMainWindow *Tutorial7Class)
    {
        Tutorial7Class->setWindowTitle(QApplication::translate("Tutorial7Class", "Tutorial7", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tutorial7Class: public Ui_Tutorial7Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL7_H
