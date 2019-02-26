/********************************************************************************
** Form generated from reading UI file 'Tool_Map.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOOL_MAP_H
#define UI_TOOL_MAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tool_MapClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Tool_MapClass)
    {
        if (Tool_MapClass->objectName().isEmpty())
            Tool_MapClass->setObjectName(QString::fromUtf8("Tool_MapClass"));
        Tool_MapClass->resize(600, 400);
        menuBar = new QMenuBar(Tool_MapClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Tool_MapClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tool_MapClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Tool_MapClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Tool_MapClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Tool_MapClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Tool_MapClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Tool_MapClass->setStatusBar(statusBar);

        retranslateUi(Tool_MapClass);

        QMetaObject::connectSlotsByName(Tool_MapClass);
    } // setupUi

    void retranslateUi(QMainWindow *Tool_MapClass)
    {
        Tool_MapClass->setWindowTitle(QApplication::translate("Tool_MapClass", "Tool_Map", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tool_MapClass: public Ui_Tool_MapClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOL_MAP_H
