/********************************************************************************
** Form generated from reading UI file 'Tutorial5.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL5_H
#define UI_TUTORIAL5_H

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

class Ui_Tutorial5Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    Widget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tutorial5Class)
    {
        if (Tutorial5Class->objectName().isEmpty())
            Tutorial5Class->setObjectName(QString::fromUtf8("Tutorial5Class"));
        Tutorial5Class->resize(789, 568);
        centralWidget = new QWidget(Tutorial5Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openGLWidget = new Widget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        Tutorial5Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tutorial5Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 789, 26));
        Tutorial5Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tutorial5Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Tutorial5Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Tutorial5Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Tutorial5Class->setStatusBar(statusBar);

        retranslateUi(Tutorial5Class);

        QMetaObject::connectSlotsByName(Tutorial5Class);
    } // setupUi

    void retranslateUi(QMainWindow *Tutorial5Class)
    {
        Tutorial5Class->setWindowTitle(QApplication::translate("Tutorial5Class", "Tutorial5", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tutorial5Class: public Ui_Tutorial5Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL5_H
