/********************************************************************************
** Form generated from reading UI file 'optionsui.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSUI_H
#define UI_OPTIONSUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_optionsui
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *optionsui)
    {
        if (optionsui->objectName().isEmpty())
            optionsui->setObjectName(QStringLiteral("optionsui"));
        optionsui->resize(640, 480);
        optionsui->setMaximumSize(QSize(640, 480));
        widget = new QWidget(optionsui);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 440, 621, 25));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        retranslateUi(optionsui);

        QMetaObject::connectSlotsByName(optionsui);
    } // setupUi

    void retranslateUi(QDialog *optionsui)
    {
        optionsui->setWindowTitle(QApplication::translate("optionsui", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
        pushButton->setText(QApplication::translate("optionsui", "\320\237\320\276\320\273\321\203\321\207\320\270\321\202\321\214", 0));
        pushButton_2->setText(QApplication::translate("optionsui", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        pushButton_3->setText(QApplication::translate("optionsui", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class optionsui: public Ui_optionsui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSUI_H
