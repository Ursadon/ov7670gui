/********************************************************************************
** Form generated from reading UI file 'ov7670.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OV7670_H
#define UI_OV7670_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ov7670
{
public:
    QAction *actionOpen;
    QAction *actionClose;
    QWidget *centralWidget;
    QPushButton *pbAutoGetStop;
    QPushButton *pbAutoGet;
    QPushButton *pbGetImage;
    QPushButton *pbParseImage;
    QProgressBar *loadpercent;
    QPushButton *pbClear;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLineEdit *leparam;
    QPushButton *pbSend;
    QLineEdit *levalue;
    QLabel *label_3;
    QPushButton *pbCameraShow;
    QPushButton *pbSettings;
    QSlider *hsServo;
    QLabel *lbServo;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ov7670)
    {
        if (ov7670->objectName().isEmpty())
            ov7670->setObjectName(QStringLiteral("ov7670"));
        ov7670->resize(460, 281);
        actionOpen = new QAction(ov7670);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionClose = new QAction(ov7670);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        centralWidget = new QWidget(ov7670);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pbAutoGetStop = new QPushButton(centralWidget);
        pbAutoGetStop->setObjectName(QStringLiteral("pbAutoGetStop"));
        pbAutoGetStop->setGeometry(QRect(200, 40, 75, 23));
        pbAutoGet = new QPushButton(centralWidget);
        pbAutoGet->setObjectName(QStringLiteral("pbAutoGet"));
        pbAutoGet->setGeometry(QRect(200, 10, 75, 23));
        pbGetImage = new QPushButton(centralWidget);
        pbGetImage->setObjectName(QStringLiteral("pbGetImage"));
        pbGetImage->setGeometry(QRect(290, 10, 75, 23));
        pbParseImage = new QPushButton(centralWidget);
        pbParseImage->setObjectName(QStringLiteral("pbParseImage"));
        pbParseImage->setGeometry(QRect(290, 40, 75, 23));
        loadpercent = new QProgressBar(centralWidget);
        loadpercent->setObjectName(QStringLiteral("loadpercent"));
        loadpercent->setGeometry(QRect(20, 20, 161, 23));
        loadpercent->setMaximum(50688);
        loadpercent->setValue(0);
        pbClear = new QPushButton(centralWidget);
        pbClear->setObjectName(QStringLiteral("pbClear"));
        pbClear->setGeometry(QRect(370, 10, 75, 23));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 60, 161, 101));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 141, 83));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        leparam = new QLineEdit(formLayoutWidget);
        leparam->setObjectName(QStringLiteral("leparam"));

        formLayout->setWidget(1, QFormLayout::FieldRole, leparam);

        pbSend = new QPushButton(formLayoutWidget);
        pbSend->setObjectName(QStringLiteral("pbSend"));

        formLayout->setWidget(3, QFormLayout::FieldRole, pbSend);

        levalue = new QLineEdit(formLayoutWidget);
        levalue->setObjectName(QStringLiteral("levalue"));

        formLayout->setWidget(2, QFormLayout::FieldRole, levalue);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        pbCameraShow = new QPushButton(centralWidget);
        pbCameraShow->setObjectName(QStringLiteral("pbCameraShow"));
        pbCameraShow->setGeometry(QRect(300, 230, 75, 23));
        pbSettings = new QPushButton(centralWidget);
        pbSettings->setObjectName(QStringLiteral("pbSettings"));
        pbSettings->setGeometry(QRect(380, 230, 75, 23));
        hsServo = new QSlider(centralWidget);
        hsServo->setObjectName(QStringLiteral("hsServo"));
        hsServo->setGeometry(QRect(240, 120, 160, 19));
        hsServo->setMinimum(21);
        hsServo->setMaximum(112);
        hsServo->setOrientation(Qt::Horizontal);
        lbServo = new QLabel(centralWidget);
        lbServo->setObjectName(QStringLiteral("lbServo"));
        lbServo->setGeometry(QRect(300, 150, 46, 13));
        ov7670->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ov7670);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ov7670->setStatusBar(statusBar);
        QWidget::setTabOrder(pbAutoGet, pbGetImage);
        QWidget::setTabOrder(pbGetImage, pbParseImage);
        QWidget::setTabOrder(pbParseImage, pbClear);
        QWidget::setTabOrder(pbClear, leparam);
        QWidget::setTabOrder(leparam, levalue);
        QWidget::setTabOrder(levalue, pbSend);
        QWidget::setTabOrder(pbSend, pbAutoGetStop);
        QWidget::setTabOrder(pbAutoGetStop, pbCameraShow);
        QWidget::setTabOrder(pbCameraShow, pbSettings);
        QWidget::setTabOrder(pbSettings, hsServo);

        retranslateUi(ov7670);

        QMetaObject::connectSlotsByName(ov7670);
    } // setupUi

    void retranslateUi(QMainWindow *ov7670)
    {
        ov7670->setWindowTitle(QApplication::translate("ov7670", "ov7670", 0));
        actionOpen->setText(QApplication::translate("ov7670", "Open", 0));
        actionClose->setText(QApplication::translate("ov7670", "Close", 0));
        pbAutoGetStop->setText(QApplication::translate("ov7670", "AutoGet stop", 0));
        pbAutoGet->setText(QApplication::translate("ov7670", "AutoGet", 0));
        pbGetImage->setText(QApplication::translate("ov7670", "GetImage", 0));
        pbParseImage->setText(QApplication::translate("ov7670", "ParseImage", 0));
        loadpercent->setFormat(QApplication::translate("ov7670", "%p%", 0));
        pbClear->setText(QApplication::translate("ov7670", "ClearBuffer", 0));
        groupBox->setTitle(QApplication::translate("ov7670", "Custom CMD", 0));
        label_2->setText(QApplication::translate("ov7670", "Param", 0));
        pbSend->setText(QApplication::translate("ov7670", "Send", 0));
        label_3->setText(QApplication::translate("ov7670", "Value", 0));
        pbCameraShow->setText(QApplication::translate("ov7670", "Camera Show", 0));
        pbSettings->setText(QApplication::translate("ov7670", "Settings", 0));
        lbServo->setText(QApplication::translate("ov7670", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class ov7670: public Ui_ov7670 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OV7670_H
