/********************************************************************************
** Form generated from reading UI file 'Tutorial1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL1_H
#define UI_TUTORIAL1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "widget.h"

QT_BEGIN_NAMESPACE

class Ui_Tutorial1Class
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    Widget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tutorial1Class)
    {
        if (Tutorial1Class->objectName().isEmpty())
            Tutorial1Class->setObjectName(QString::fromUtf8("Tutorial1Class"));
        Tutorial1Class->resize(881, 620);
        centralWidget = new QWidget(Tutorial1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        openGLWidget = new Widget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        gridLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        Tutorial1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tutorial1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 881, 26));
        Tutorial1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tutorial1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Tutorial1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Tutorial1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Tutorial1Class->setStatusBar(statusBar);

        retranslateUi(Tutorial1Class);

        QMetaObject::connectSlotsByName(Tutorial1Class);
    } // setupUi

    void retranslateUi(QMainWindow *Tutorial1Class)
    {
        Tutorial1Class->setWindowTitle(QApplication::translate("Tutorial1Class", "Tutorial1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tutorial1Class: public Ui_Tutorial1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL1_H
