/********************************************************************************
** Form generated from reading UI file 'Tutorial8.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL8_H
#define UI_TUTORIAL8_H

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

class Ui_Tutorial8Class
{
public:
    QWidget *centralWidget;
    QGridLayout *qGraidLayout;
    Widget *openGLWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tutorial8Class)
    {
        if (Tutorial8Class->objectName().isEmpty())
            Tutorial8Class->setObjectName(QString::fromUtf8("Tutorial8Class"));
        Tutorial8Class->resize(846, 583);
        centralWidget = new QWidget(Tutorial8Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        qGraidLayout = new QGridLayout(centralWidget);
        qGraidLayout->setSpacing(6);
        qGraidLayout->setContentsMargins(11, 11, 11, 11);
        qGraidLayout->setObjectName(QString::fromUtf8("qGraidLayout"));
        openGLWidget = new Widget(centralWidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        qGraidLayout->addWidget(openGLWidget, 0, 0, 1, 1);

        Tutorial8Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tutorial8Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 846, 26));
        Tutorial8Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tutorial8Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Tutorial8Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Tutorial8Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Tutorial8Class->setStatusBar(statusBar);

        retranslateUi(Tutorial8Class);

        QMetaObject::connectSlotsByName(Tutorial8Class);
    } // setupUi

    void retranslateUi(QMainWindow *Tutorial8Class)
    {
        Tutorial8Class->setWindowTitle(QCoreApplication::translate("Tutorial8Class", "Tutorial8", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tutorial8Class: public Ui_Tutorial8Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL8_H
