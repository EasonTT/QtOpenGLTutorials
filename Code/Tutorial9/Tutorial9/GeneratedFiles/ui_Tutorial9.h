/********************************************************************************
** Form generated from reading UI file 'Tutorial9.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL9_H
#define UI_TUTORIAL9_H

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

class Ui_Tutorial9Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridWidget;
    Widget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tutorial9Class)
    {
        if (Tutorial9Class->objectName().isEmpty())
            Tutorial9Class->setObjectName(QString::fromUtf8("Tutorial9Class"));
        Tutorial9Class->resize(1028, 652);
        centralWidget = new QWidget(Tutorial9Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridWidget = new QGridLayout(centralWidget);
        gridWidget->setSpacing(6);
        gridWidget->setContentsMargins(11, 11, 11, 11);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        openGLWidget = new Widget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        gridWidget->addWidget(openGLWidget, 0, 0, 1, 1);

        Tutorial9Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tutorial9Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1028, 26));
        Tutorial9Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tutorial9Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Tutorial9Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Tutorial9Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Tutorial9Class->setStatusBar(statusBar);

        retranslateUi(Tutorial9Class);

        QMetaObject::connectSlotsByName(Tutorial9Class);
    } // setupUi

    void retranslateUi(QMainWindow *Tutorial9Class)
    {
        Tutorial9Class->setWindowTitle(QApplication::translate("Tutorial9Class", "Tutorial9", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tutorial9Class: public Ui_Tutorial9Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL9_H
