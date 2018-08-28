/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPlainTextEdit *inputEdit;
    QPlainTextEdit *outputArea;
    QLineEdit *keyEdit;
    QLabel *label_2;
    QPushButton *startButton;
    QLabel *label_3;
    QLabel *label_4;
    QRadioButton *radio1;
    QRadioButton *radio2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(720, 295);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 67, 22));
        inputEdit = new QPlainTextEdit(centralWidget);
        inputEdit->setObjectName(QStringLiteral("inputEdit"));
        inputEdit->setGeometry(QRect(10, 40, 271, 220));
        outputArea = new QPlainTextEdit(centralWidget);
        outputArea->setObjectName(QStringLiteral("outputArea"));
        outputArea->setGeometry(QRect(440, 40, 271, 220));
        outputArea->setReadOnly(true);
        keyEdit = new QLineEdit(centralWidget);
        keyEdit->setObjectName(QStringLiteral("keyEdit"));
        keyEdit->setGeometry(QRect(290, 190, 141, 30));
        keyEdit->setMaxLength(64);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(440, 10, 67, 22));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(290, 230, 141, 30));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 160, 67, 22));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(290, 40, 67, 22));
        radio1 = new QRadioButton(centralWidget);
        radio1->setObjectName(QStringLiteral("radio1"));
        radio1->setGeometry(QRect(290, 70, 114, 28));
        radio1->setChecked(true);
        radio2 = new QRadioButton(centralWidget);
        radio2->setObjectName(QStringLiteral("radio2"));
        radio2->setGeometry(QRect(290, 90, 114, 28));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SwiftCrypt GUI", nullptr));
        label->setText(QApplication::translate("MainWindow", "Input", nullptr));
        keyEdit->setPlaceholderText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Output", nullptr));
        startButton->setText(QApplication::translate("MainWindow", "Encrypt", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Key", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Mode", nullptr));
        radio1->setText(QApplication::translate("MainWindow", "Encrypt", nullptr));
        radio2->setText(QApplication::translate("MainWindow", "Decrypt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
