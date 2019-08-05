/********************************************************************************
** Form generated from reading UI file 'Tutorial6.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL6_H
#define UI_TUTORIAL6_H

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

class Ui_Tutorial6Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    Widget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tutorial6Class)
    {
        if (Tutorial6Class->objectName().isEmpty())
            Tutorial6Class->setObjectName(QString::fromUtf8("Tutorial6Class"));
        Tutorial6Class->resize(876, 638);
        centralWidget = new QWidget(Tutorial6Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openGLWidget = new Widget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        Tutorial6Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tutorial6Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 876, 26));
        Tutorial6Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tutorial6Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Tutorial6Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Tutorial6Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Tutorial6Class->setStatusBar(statusBar);

        retranslateUi(Tutorial6Class);

        QMetaObject::connectSlotsByName(Tutorial6Class);
    } // setupUi

    void retranslateUi(QMainWindow *Tutorial6Class)
    {
        Tutorial6Class->setWindowTitle(QCoreApplication::translate("Tutorial6Class", "Tutorial6", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tutorial6Class: public Ui_Tutorial6Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL6_H
