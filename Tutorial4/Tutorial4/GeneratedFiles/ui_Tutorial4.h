/********************************************************************************
** Form generated from reading UI file 'Tutorial4.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL4_H
#define UI_TUTORIAL4_H

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

class Ui_Tutorial4Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    Widget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tutorial4Class)
    {
        if (Tutorial4Class->objectName().isEmpty())
            Tutorial4Class->setObjectName(QString::fromUtf8("Tutorial4Class"));
        Tutorial4Class->resize(1020, 592);
        centralWidget = new QWidget(Tutorial4Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openGLWidget = new Widget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        Tutorial4Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tutorial4Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1020, 26));
        Tutorial4Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tutorial4Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Tutorial4Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Tutorial4Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Tutorial4Class->setStatusBar(statusBar);

        retranslateUi(Tutorial4Class);

        QMetaObject::connectSlotsByName(Tutorial4Class);
    } // setupUi

    void retranslateUi(QMainWindow *Tutorial4Class)
    {
        Tutorial4Class->setWindowTitle(QApplication::translate("Tutorial4Class", "Tutorial4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tutorial4Class: public Ui_Tutorial4Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL4_H
