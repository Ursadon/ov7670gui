/********************************************************************************
** Form generated from reading UI file 'camerashow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERASHOW_H
#define UI_CAMERASHOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_camerashow
{
public:
    QLabel *imageLabel;

    void setupUi(QDialog *camerashow)
    {
        if (camerashow->objectName().isEmpty())
            camerashow->setObjectName(QStringLiteral("camerashow"));
        camerashow->resize(320, 240);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(camerashow->sizePolicy().hasHeightForWidth());
        camerashow->setSizePolicy(sizePolicy);
        camerashow->setMinimumSize(QSize(320, 240));
        camerashow->setMaximumSize(QSize(320, 240));
        camerashow->setCursor(QCursor(Qt::ForbiddenCursor));
        camerashow->setSizeGripEnabled(false);
        camerashow->setModal(false);
        imageLabel = new QLabel(camerashow);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));
        imageLabel->setGeometry(QRect(70, 40, 176, 144));
        imageLabel->setMinimumSize(QSize(176, 144));
        imageLabel->setMaximumSize(QSize(640, 480));
        imageLabel->setBaseSize(QSize(176, 144));
        imageLabel->setCursor(QCursor(Qt::ForbiddenCursor));
        imageLabel->setFrameShape(QFrame::Box);
        imageLabel->setFrameShadow(QFrame::Plain);
        imageLabel->setLineWidth(1);
        imageLabel->setMidLineWidth(0);
        imageLabel->setTextFormat(Qt::PlainText);
        imageLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(camerashow);

        QMetaObject::connectSlotsByName(camerashow);
    } // setupUi

    void retranslateUi(QDialog *camerashow)
    {
        camerashow->setWindowTitle(QApplication::translate("camerashow", "ov7670 camera", 0));
        imageLabel->setText(QApplication::translate("camerashow", "Image", 0));
    } // retranslateUi

};

namespace Ui {
    class camerashow: public Ui_camerashow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERASHOW_H
