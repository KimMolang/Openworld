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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tool_MapClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_look;
    QLabel *label_give;
    QPushButton *button_bag;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Tool_MapClass)
    {
        if (Tool_MapClass->objectName().isEmpty())
            Tool_MapClass->setObjectName(QString::fromUtf8("Tool_MapClass"));
        Tool_MapClass->resize(1105, 764);
        centralWidget = new QWidget(Tool_MapClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(31, 21, 95, 74));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_look = new QLabel(widget);
        label_look->setObjectName(QString::fromUtf8("label_look"));

        verticalLayout->addWidget(label_look);

        label_give = new QLabel(widget);
        label_give->setObjectName(QString::fromUtf8("label_give"));

        verticalLayout->addWidget(label_give);

        button_bag = new QPushButton(widget);
        button_bag->setObjectName(QString::fromUtf8("button_bag"));

        verticalLayout->addWidget(button_bag);

        Tool_MapClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Tool_MapClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1105, 26));
        Tool_MapClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Tool_MapClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Tool_MapClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Tool_MapClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Tool_MapClass->setStatusBar(statusBar);
        toolBar = new QToolBar(Tool_MapClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        Tool_MapClass->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(Tool_MapClass);

        QMetaObject::connectSlotsByName(Tool_MapClass);
    } // setupUi

    void retranslateUi(QMainWindow *Tool_MapClass)
    {
        Tool_MapClass->setWindowTitle(QApplication::translate("Tool_MapClass", "Tool_Map", nullptr));
        label_look->setText(QApplication::translate("Tool_MapClass", "Look", nullptr));
        label_give->setText(QApplication::translate("Tool_MapClass", "Give", nullptr));
#ifndef QT_NO_TOOLTIP
        button_bag->setToolTip(QApplication::translate("Tool_MapClass", "<html><head/><body><p>Please!</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        button_bag->setText(QApplication::translate("Tool_MapClass", "Bag", nullptr));
        toolBar->setWindowTitle(QApplication::translate("Tool_MapClass", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tool_MapClass: public Ui_Tool_MapClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOOL_MAP_H
