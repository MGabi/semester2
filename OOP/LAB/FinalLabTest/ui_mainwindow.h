/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QListWidget *jumpersList;
    QPushButton *jumpBtn;
    QListWidget *afterJumpList;
    QPushButton *saveBtn;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(871, 540);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        jumpersList = new QListWidget(centralWidget);
        jumpersList->setObjectName(QStringLiteral("jumpersList"));

        gridLayout->addWidget(jumpersList, 0, 0, 1, 1);

        jumpBtn = new QPushButton(centralWidget);
        jumpBtn->setObjectName(QStringLiteral("jumpBtn"));

        gridLayout->addWidget(jumpBtn, 1, 0, 1, 1);

        afterJumpList = new QListWidget(centralWidget);
        afterJumpList->setObjectName(QStringLiteral("afterJumpList"));

        gridLayout->addWidget(afterJumpList, 0, 1, 1, 1);

        saveBtn = new QPushButton(centralWidget);
        saveBtn->setObjectName(QStringLiteral("saveBtn"));

        gridLayout->addWidget(saveBtn, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 871, 23));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Jumpers", nullptr));
        jumpBtn->setText(QApplication::translate("MainWindow", "JUMP", nullptr));
        saveBtn->setText(QApplication::translate("MainWindow", "SAVE TO FILE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
