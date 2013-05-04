#include "camerashow.h"
#include "ui_camerashow.h"

CameraShow::CameraShow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::camerashow)
{
	ui->setupUi(this);
}

CameraShow::~CameraShow()
{
	delete ui;
}
void CameraShow::showimage(QImage *image) {
	ui->imageLabel->setPixmap(QPixmap::fromImage(*image));
}
