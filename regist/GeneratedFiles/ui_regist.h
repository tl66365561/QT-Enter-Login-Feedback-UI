/********************************************************************************
** Form generated from reading UI file 'regist.ui'
**
** Created: Fri Dec 20 15:47:07 2019
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGIST_H
#define UI_REGIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *registClass)
    {
        if (registClass->objectName().isEmpty())
            registClass->setObjectName(QString::fromUtf8("registClass"));
        registClass->resize(600, 400);
        menuBar = new QMenuBar(registClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        registClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(registClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        registClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(registClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        registClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(registClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        registClass->setStatusBar(statusBar);

        retranslateUi(registClass);

        QMetaObject::connectSlotsByName(registClass);
    } // setupUi

    void retranslateUi(QMainWindow *registClass)
    {
        registClass->setWindowTitle(QApplication::translate("registClass", "regist", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class registClass: public Ui_registClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGIST_H
