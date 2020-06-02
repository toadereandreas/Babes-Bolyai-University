/********************************************************************************
** Form generated from reading UI file 'studentgrades.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDENTGRADES_H
#define UI_STUDENTGRADES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StudentGradesClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StudentGradesClass)
    {
        if (StudentGradesClass->objectName().isEmpty())
            StudentGradesClass->setObjectName(QString::fromUtf8("StudentGradesClass"));
        StudentGradesClass->resize(600, 400);
        menuBar = new QMenuBar(StudentGradesClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        StudentGradesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StudentGradesClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        StudentGradesClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(StudentGradesClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        StudentGradesClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(StudentGradesClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        StudentGradesClass->setStatusBar(statusBar);

        retranslateUi(StudentGradesClass);

        QMetaObject::connectSlotsByName(StudentGradesClass);
    } // setupUi

    void retranslateUi(QMainWindow *StudentGradesClass)
    {
        StudentGradesClass->setWindowTitle(QApplication::translate("StudentGradesClass", "StudentGrades", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StudentGradesClass: public Ui_StudentGradesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDENTGRADES_H
