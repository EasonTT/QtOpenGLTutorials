/********************************************************************************
** Form generated from reading UI file 'Tutorial3.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL3_H
#define UI_TUTORIAL3_H

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

class Ui_Tutorial3Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    Widget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tutorial3Class)
    {
        if (Tutorial3Class->objectName().isEmpty())
            Tutorial3Class->setObjectName(QString::fromUtf8("Tutorial3Class"));
        Tutorial3Class->resize(928, 653);
        centralWidget = new QWidget(Tutorial3Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openGLWidget = new Widget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        Tutorial3Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tutorial3Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 928, 26));
        Tutorial3Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tutorial3Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Tutorial3Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Tutorial3Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Tutorial3Class->setStatusBar(statusBar);

        retranslateUi(Tutorial3Class);

        QMetaObject::connectSlotsByName(Tutorial3Class);
    } // setupUi

    void retranslateUi(QMainWindow *Tutorial3Class)
    {
        Tutorial3Class->setWindowTitle(QApplication::translate("Tutorial3Class", "Tutorial3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tutorial3Class: public Ui_Tutorial3Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL3_H
