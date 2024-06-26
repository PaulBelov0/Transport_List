/********************************************************************************
** Form generated from reading UI file 'SuccessDeleting.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUCCESSDELETING_H
#define UI_SUCCESSDELETING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SuccessDeleting
{
public:
    QPushButton *Ok;
    QLabel *label;

    void setupUi(QDialog *SuccessDeleting)
    {
        if (SuccessDeleting->objectName().isEmpty())
            SuccessDeleting->setObjectName("SuccessDeleting");
        SuccessDeleting->resize(320, 240);
        Ok = new QPushButton(SuccessDeleting);
        Ok->setObjectName("Ok");
        Ok->setGeometry(QRect(120, 180, 83, 29));
        label = new QLabel(SuccessDeleting);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 80, 241, 41));
        QFont font;
        font.setPointSize(11);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(SuccessDeleting);

        QMetaObject::connectSlotsByName(SuccessDeleting);
    } // setupUi

    void retranslateUi(QDialog *SuccessDeleting)
    {
        SuccessDeleting->setWindowTitle(QCoreApplication::translate("SuccessDeleting", "Dialog", nullptr));
        Ok->setText(QCoreApplication::translate("SuccessDeleting", "OK", nullptr));
        label->setText(QCoreApplication::translate("SuccessDeleting", "Element deleted successful!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SuccessDeleting: public Ui_SuccessDeleting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUCCESSDELETING_H
