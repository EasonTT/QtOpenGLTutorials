/********************************************************************************
** Form generated from reading UI file 'Tutorial2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL2_H
#define UI_TUTORIAL2_H

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

class Ui_Tutorial2Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    Widget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tutorial2Class)
    {
        if (Tutorial2Class->objectName().isEmpty())
            Tutorial2Class->setObjectName(QString::fromUtf8("Tutorial2Class"));
        Tutorial2Class->resize(1068, 770);
        centralWidget = new QWidget(Tutorial2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openGLWidget = new Widget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        Tutorial2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tutorial2Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1068, 26));
        Tutorial2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tutorial2Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Tutorial2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Tutorial2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Tutorial2Class->setStatusBar(statusBar);

        retranslateUi(Tutorial2Class);

        QMetaObject::connectSlotsByName(Tutorial2Class);
    } // setupUi

    void retranslateUi(QMainWindow *Tutorial2Class)
    {
        Tutorial2Class->setWindowTitle(QApplication::translate("Tutorial2Class", "Tutorial2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tutorial2Class: public Ui_Tutorial2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL2_H
