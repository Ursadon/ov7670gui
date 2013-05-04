#ifndef CAMERASHOW_H
#define CAMERASHOW_H

#include <QDialog>

namespace Ui {
	class camerashow;
}

class CameraShow : public QDialog
{
		Q_OBJECT
		
	public:
		explicit CameraShow(QWidget *parent = 0);
		~CameraShow();
		void showimage(QImage *image);

	private:
		Ui::camerashow *ui;
};

#endif // CAMERASHOW_H
