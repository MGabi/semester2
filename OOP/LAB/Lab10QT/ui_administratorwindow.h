/********************************************************************************
** Form generated from reading UI file 'administratorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATORWINDOW_H
#define UI_ADMINISTRATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdministratorWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *layoutTable;
    QTableView *tableCourses;
    QPushButton *buttonDelete;
    QPushButton *buttonUpdate;
    QFormLayout *layoutAdd;
    QLabel *titleLabel;
    QLineEdit *titleLineEdit;
    QLabel *presenterLabel;
    QLineEdit *presenterLineEdit;
    QLabel *refLinkLabel;
    QLineEdit *refLinkLineEdit;
    QLabel *durationLabel;
    QLineEdit *durationLineEdit;
    QLabel *likesLabel;
    QLineEdit *likesLineEdit;
    QPushButton *buttonAdd;

    void setupUi(QWidget *AdministratorWindow)
    {
        if (AdministratorWindow->objectName().isEmpty())
            AdministratorWindow->setObjectName(QStringLiteral("AdministratorWindow"));
        AdministratorWindow->setEnabled(true);
        AdministratorWindow->resize(1101, 420);
        gridLayout = new QGridLayout(AdministratorWindow);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        layoutTable = new QVBoxLayout();
        layoutTable->setObjectName(QStringLiteral("layoutTable"));
        tableCourses = new QTableView(AdministratorWindow);
        tableCourses->setObjectName(QStringLiteral("tableCourses"));

        layoutTable->addWidget(tableCourses);

        buttonDelete = new QPushButton(AdministratorWindow);
        buttonDelete->setObjectName(QStringLiteral("buttonDelete"));

        layoutTable->addWidget(buttonDelete);

        buttonUpdate = new QPushButton(AdministratorWindow);
        buttonUpdate->setObjectName(QStringLiteral("buttonUpdate"));

        layoutTable->addWidget(buttonUpdate);


        gridLayout->addLayout(layoutTable, 0, 0, 1, 1);

        layoutAdd = new QFormLayout();
        layoutAdd->setObjectName(QStringLiteral("layoutAdd"));
        layoutAdd->setSizeConstraint(QLayout::SetMaximumSize);
        titleLabel = new QLabel(AdministratorWindow);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));

        layoutAdd->setWidget(0, QFormLayout::LabelRole, titleLabel);

        titleLineEdit = new QLineEdit(AdministratorWindow);
        titleLineEdit->setObjectName(QStringLiteral("titleLineEdit"));

        layoutAdd->setWidget(0, QFormLayout::FieldRole, titleLineEdit);

        presenterLabel = new QLabel(AdministratorWindow);
        presenterLabel->setObjectName(QStringLiteral("presenterLabel"));

        layoutAdd->setWidget(1, QFormLayout::LabelRole, presenterLabel);

        presenterLineEdit = new QLineEdit(AdministratorWindow);
        presenterLineEdit->setObjectName(QStringLiteral("presenterLineEdit"));

        layoutAdd->setWidget(1, QFormLayout::FieldRole, presenterLineEdit);

        refLinkLabel = new QLabel(AdministratorWindow);
        refLinkLabel->setObjectName(QStringLiteral("refLinkLabel"));

        layoutAdd->setWidget(2, QFormLayout::LabelRole, refLinkLabel);

        refLinkLineEdit = new QLineEdit(AdministratorWindow);
        refLinkLineEdit->setObjectName(QStringLiteral("refLinkLineEdit"));

        layoutAdd->setWidget(2, QFormLayout::FieldRole, refLinkLineEdit);

        durationLabel = new QLabel(AdministratorWindow);
        durationLabel->setObjectName(QStringLiteral("durationLabel"));

        layoutAdd->setWidget(3, QFormLayout::LabelRole, durationLabel);

        durationLineEdit = new QLineEdit(AdministratorWindow);
        durationLineEdit->setObjectName(QStringLiteral("durationLineEdit"));

        layoutAdd->setWidget(3, QFormLayout::FieldRole, durationLineEdit);

        likesLabel = new QLabel(AdministratorWindow);
        likesLabel->setObjectName(QStringLiteral("likesLabel"));

        layoutAdd->setWidget(4, QFormLayout::LabelRole, likesLabel);

        likesLineEdit = new QLineEdit(AdministratorWindow);
        likesLineEdit->setObjectName(QStringLiteral("likesLineEdit"));

        layoutAdd->setWidget(4, QFormLayout::FieldRole, likesLineEdit);

        buttonAdd = new QPushButton(AdministratorWindow);
        buttonAdd->setObjectName(QStringLiteral("buttonAdd"));

        layoutAdd->setWidget(5, QFormLayout::FieldRole, buttonAdd);


        gridLayout->addLayout(layoutAdd, 0, 1, 1, 1);


        retranslateUi(AdministratorWindow);

        QMetaObject::connectSlotsByName(AdministratorWindow);
    } // setupUi

    void retranslateUi(QWidget *AdministratorWindow)
    {
        AdministratorWindow->setWindowTitle(QApplication::translate("AdministratorWindow", "Administrator", nullptr));
        buttonDelete->setText(QApplication::translate("AdministratorWindow", "Delete", nullptr));
        buttonUpdate->setText(QApplication::translate("AdministratorWindow", "Update", nullptr));
        titleLabel->setText(QApplication::translate("AdministratorWindow", "Title", nullptr));
        titleLineEdit->setText(QString());
        titleLineEdit->setPlaceholderText(QApplication::translate("AdministratorWindow", "Title", nullptr));
        presenterLabel->setText(QApplication::translate("AdministratorWindow", "Presenter", nullptr));
        presenterLineEdit->setPlaceholderText(QApplication::translate("AdministratorWindow", "Presenter", nullptr));
        refLinkLabel->setText(QApplication::translate("AdministratorWindow", "Ref link", nullptr));
        refLinkLineEdit->setPlaceholderText(QApplication::translate("AdministratorWindow", "Ref link", nullptr));
        durationLabel->setText(QApplication::translate("AdministratorWindow", "<html><head/><body><p><span style=\" color:#2e3436;\">Duration</span></p></body></html>", nullptr));
        durationLineEdit->setPlaceholderText(QApplication::translate("AdministratorWindow", "Duration (seconds)", nullptr));
        likesLabel->setText(QApplication::translate("AdministratorWindow", "Likes", nullptr));
        likesLineEdit->setPlaceholderText(QApplication::translate("AdministratorWindow", "Likes", nullptr));
        buttonAdd->setText(QApplication::translate("AdministratorWindow", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdministratorWindow: public Ui_AdministratorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORWINDOW_H
