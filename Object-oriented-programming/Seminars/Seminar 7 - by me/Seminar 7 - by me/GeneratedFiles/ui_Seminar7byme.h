/********************************************************************************
** Form generated from reading UI file 'Seminar7byme.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEMINAR7BYME_H
#define UI_SEMINAR7BYME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Seminar7bymeClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Seminar7bymeClass)
    {
        if (Seminar7bymeClass->objectName().isEmpty())
            Seminar7bymeClass->setObjectName(QString::fromUtf8("Seminar7bymeClass"));
        Seminar7bymeClass->resize(600, 400);
        menuBar = new QMenuBar(Seminar7bymeClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        Seminar7bymeClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Seminar7bymeClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Seminar7bymeClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Seminar7bymeClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Seminar7bymeClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Seminar7bymeClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Seminar7bymeClass->setStatusBar(statusBar);

        retranslateUi(Seminar7bymeClass);

        QMetaObject::connectSlotsByName(Seminar7bymeClass);
    } // setupUi

    void retranslateUi(QMainWindow *Seminar7bymeClass)
    {
        Seminar7bymeClass->setWindowTitle(QApplication::translate("Seminar7bymeClass", "Seminar7byme", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Seminar7bymeClass: public Ui_Seminar7bymeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEMINAR7BYME_H
