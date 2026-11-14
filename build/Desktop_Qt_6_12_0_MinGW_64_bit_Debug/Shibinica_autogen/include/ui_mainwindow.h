/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineLetter;
    QPushButton *btnGuess;
    QLabel *labelWord;
    QLabel *labelAttempts;
    QLabel *labelHangman;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(500, 400);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineLetter = new QLineEdit(centralwidget);
        lineLetter->setObjectName("lineLetter");
        lineLetter->setGeometry(QRect(200, 260, 113, 28));
        lineLetter->setMaxLength(1);
        btnGuess = new QPushButton(centralwidget);
        btnGuess->setObjectName("btnGuess");
        btnGuess->setGeometry(QRect(210, 300, 90, 29));
        labelWord = new QLabel(centralwidget);
        labelWord->setObjectName("labelWord");
        labelWord->setGeometry(QRect(130, 210, 251, 31));
        labelWord->setTextFormat(Qt::TextFormat::AutoText);
        labelWord->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelAttempts = new QLabel(centralwidget);
        labelAttempts->setObjectName("labelAttempts");
        labelAttempts->setGeometry(QRect(20, 10, 131, 51));
        labelHangman = new QLabel(centralwidget);
        labelHangman->setObjectName("labelHangman");
        labelHangman->setGeometry(QRect(170, 40, 201, 161));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 500, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnGuess->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        labelWord->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelAttempts->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelHangman->setText(QCoreApplication::translate("MainWindow", "----\n"
"| |\n"
"|\n"
"|\n"
"|", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
