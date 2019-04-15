/********************************************************************************
** Form generated from reading UI file 'showtext.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWTEXT_H
#define UI_SHOWTEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_ShowText
{
public:
    QTextBrowser *textOutput;

    void setupUi(QDialog *ShowText)
    {
        if (ShowText->objectName().isEmpty())
            ShowText->setObjectName(QStringLiteral("ShowText"));
        ShowText->resize(400, 300);
        textOutput = new QTextBrowser(ShowText);
        textOutput->setObjectName(QStringLiteral("textOutput"));
        textOutput->setGeometry(QRect(30, 30, 341, 201));

        retranslateUi(ShowText);

        QMetaObject::connectSlotsByName(ShowText);
    } // setupUi

    void retranslateUi(QDialog *ShowText)
    {
        ShowText->setWindowTitle(QApplication::translate("ShowText", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ShowText: public Ui_ShowText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWTEXT_H
