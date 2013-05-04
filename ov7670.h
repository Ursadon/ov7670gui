#ifndef OV7670_H
#define OV7670_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QQueue>
#include "camerashow.h"
#include "optionsui.h"

const unsigned char
  FEND  = 0xC0,        // Frame END
  FESC  = 0xDB,        // Frame ESCape
  TFEND = 0xDC,        // Transposed Frame END
  TFESC = 0xDD;        // Transposed Frame ESCape

namespace Ui {
	class ov7670;
}

class ov7670 : public QMainWindow
{
		Q_OBJECT
		
	public:
		explicit ov7670(QWidget *parent = 0);
		~ov7670();
		enum Format {
		  MONO = 0,
		  RGB888 = 1,
		  YCBCR422 = 2,
			OWN = 3
		};
		QQueue<QByteArray> tx_queue;
	private slots:
		void on_pbAutoGet_clicked();
		void on_pbAutoGetStop_clicked();
		void readRequest();
		void on_pbGetImage_clicked();
		void autoget_timeout();

		void on_pbSend_clicked();
		void on_pbClear_clicked();
		void on_pbParseImage_clicked();

		void on_pbCameraShow_clicked();

		void on_pbSettings_clicked();

		void on_hsServo_sliderMoved(int position);

		void on_hsServo_valueChanged(int value);

		void send_queue();

	private:
		Ui::ov7670 *ui;
		QSerialPort *serialPort;
		QImage *image;
		QByteArray message;
		QVector<QRgb> decode(QByteArray);
		QByteArray serialdata;
		void saturate(int&, int, int);
		void display(QByteArray incomingData);
		unsigned int itrx;
		QTimer *autoget_timer;
		QTimer *send_queue_timer;
		QTimer *Tx_timer;
		CameraShow *camera_win;
		OptionsWindow *options_win;

		bool sending;
		void send_packet(unsigned char addr, unsigned char cmd, QByteArray data);
		QByteArray wake_stuffbyte(QByteArray packet);
		QByteArray wake_stuffbyte(unsigned char packet);

};

#endif // OV7670_H
