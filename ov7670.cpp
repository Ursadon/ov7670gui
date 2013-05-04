#include "ov7670.h"
#include "ui_ov7670.h"
#include "camerashow.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QStatusBar>
#include <QDebug>

const unsigned char crc8Table[256] = {
	0x00, 0x31, 0x62, 0x53, 0xC4, 0xF5, 0xA6, 0x97,
	0xB9, 0x88, 0xDB, 0xEA, 0x7D, 0x4C, 0x1F, 0x2E,
	0x43, 0x72, 0x21, 0x10, 0x87, 0xB6, 0xE5, 0xD4,
	0xFA, 0xCB, 0x98, 0xA9, 0x3E, 0x0F, 0x5C, 0x6D,
	0x86, 0xB7, 0xE4, 0xD5, 0x42, 0x73, 0x20, 0x11,
	0x3F, 0x0E, 0x5D, 0x6C, 0xFB, 0xCA, 0x99, 0xA8,
	0xC5, 0xF4, 0xA7, 0x96, 0x01, 0x30, 0x63, 0x52,
	0x7C, 0x4D, 0x1E, 0x2F, 0xB8, 0x89, 0xDA, 0xEB,
	0x3D, 0x0C, 0x5F, 0x6E, 0xF9, 0xC8, 0x9B, 0xAA,
	0x84, 0xB5, 0xE6, 0xD7, 0x40, 0x71, 0x22, 0x13,
	0x7E, 0x4F, 0x1C, 0x2D, 0xBA, 0x8B, 0xD8, 0xE9,
	0xC7, 0xF6, 0xA5, 0x94, 0x03, 0x32, 0x61, 0x50,
	0xBB, 0x8A, 0xD9, 0xE8, 0x7F, 0x4E, 0x1D, 0x2C,
	0x02, 0x33, 0x60, 0x51, 0xC6, 0xF7, 0xA4, 0x95,
	0xF8, 0xC9, 0x9A, 0xAB, 0x3C, 0x0D, 0x5E, 0x6F,
	0x41, 0x70, 0x23, 0x12, 0x85, 0xB4, 0xE7, 0xD6,
	0x7A, 0x4B, 0x18, 0x29, 0xBE, 0x8F, 0xDC, 0xED,
	0xC3, 0xF2, 0xA1, 0x90, 0x07, 0x36, 0x65, 0x54,
	0x39, 0x08, 0x5B, 0x6A, 0xFD, 0xCC, 0x9F, 0xAE,
	0x80, 0xB1, 0xE2, 0xD3, 0x44, 0x75, 0x26, 0x17,
	0xFC, 0xCD, 0x9E, 0xAF, 0x38, 0x09, 0x5A, 0x6B,
	0x45, 0x74, 0x27, 0x16, 0x81, 0xB0, 0xE3, 0xD2,
	0xBF, 0x8E, 0xDD, 0xEC, 0x7B, 0x4A, 0x19, 0x28,
	0x06, 0x37, 0x64, 0x55, 0xC2, 0xF3, 0xA0, 0x91,
	0x47, 0x76, 0x25, 0x14, 0x83, 0xB2, 0xE1, 0xD0,
	0xFE, 0xCF, 0x9C, 0xAD, 0x3A, 0x0B, 0x58, 0x69,
	0x04, 0x35, 0x66, 0x57, 0xC0, 0xF1, 0xA2, 0x93,
	0xBD, 0x8C, 0xDF, 0xEE, 0x79, 0x48, 0x1B, 0x2A,
	0xC1, 0xF0, 0xA3, 0x92, 0x05, 0x34, 0x67, 0x56,
	0x78, 0x49, 0x1A, 0x2B, 0xBC, 0x8D, 0xDE, 0xEF,
	0x82, 0xB3, 0xE0, 0xD1, 0x46, 0x77, 0x24, 0x15,
	0x3B, 0x0A, 0x59, 0x68, 0xFF, 0xCE, 0x9D, 0xAC
};

ov7670::ov7670(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::ov7670)
{
	ui->setupUi(this);
	message = 0;
	sending = 0;
	image = new QImage(176,144,QImage::Format_RGB888);
	serialPort = new QSerialPort();
	camera_win = new CameraShow();
	options_win = new OptionsWindow();
	options_win->setParent(this);
	options_win->setWindowFlags(Qt::Tool | Qt::WindowCloseButtonHint);
	camera_win->showimage(image);
	camera_win->setParent(this);
	camera_win->setWindowFlags(Qt::Tool | Qt::WindowCloseButtonHint);
	serialPort->setPortName("COM3");
	serialPort->setBaudRate(480000);
	serialPort->setDataBits(QSerialPort::Data8);
	serialPort->setParity(QSerialPort::NoParity);
	serialPort->setStopBits(QSerialPort::OneStop);
	serialPort->setFlowControl(QSerialPort::NoFlowControl);
	if (!serialPort->open(QIODevice::ReadWrite)) {
		statusBar()->showMessage(tr("Can't open %1, error code %2").arg(serialPort->portName()).arg(serialPort->error()), 2000 );
	}
	connect(serialPort, SIGNAL(readyRead()), this, SLOT(readRequest()));
	autoget_timer = new QTimer(this);
	connect(autoget_timer, SIGNAL(timeout()), this, SLOT(autoget_timeout()));

	send_queue_timer = new QTimer(this);
	connect(send_queue_timer, SIGNAL(timeout()), this, SLOT(send_queue()));

	//Tx_timer->start(50);
	send_queue_timer->start(100);

}

ov7670::~ov7670()
{
	delete ui;
	delete serialPort;
	delete camera_win;
	delete options_win;
}

void ov7670::readRequest() {
	serialdata.append(serialPort->readAll());
	ui->loadpercent->setValue(serialdata.size());
}

QVector<QRgb> ov7670::decode(QByteArray data)
{
	QVector<QRgb> pixels;
	int format = YCBCR422;
	bool grayscale = 0;

	switch (format) {
		case OWN:
			for (int i = 0; i < data.size(); i++) {
				int Yb = quint8(data.at(i))&0x0F;

				pixels.append(qRgb(Yb, Yb, Yb));
			}
			break;
		case MONO:
			for (int i = 0; i < data.size(); i++) {
				int level = quint8(data.at(i));
				pixels.append(qRgb(level, level, level));
			}
			break;

		case RGB888:
			if (grayscale) {
				for (int i = 0; i < data.size(); i += 3) {
					int red = quint8(data.at(i));
					int green = quint8(data.at(i + 1));
					int blue = quint8(data.at(i + 2));
					int gray = (red + green + blue) / 3;

					pixels.append(qRgb(gray, gray, gray));
				}
			} else {
				for (int i = 0; i < data.size(); i += 3) {
					int red = quint8(data.at(i));
					int green = quint8(data.at(i + 1));
					int blue = quint8(data.at(i + 2));

					pixels.append(qRgb(red, green, blue));
				}
			}
			break;

		case YCBCR422:
			if (grayscale) {
				for (int i = 0; i < data.size(); i += 4) {
					int y1 = quint8(data.at(i + 1));
					int y2 = quint8(data.at(i + 3));

					pixels.append(qRgb(y1, y1, y1));
					pixels.append(qRgb(y2, y2, y2));
				}
			} else {
				const int k13 = int(1.402f * (1 << 16));
				const int k22 = int(0.334f * (1 << 16));
				const int k23 = int(0.714f * (1 << 16));
				const int k32 = int(1.772f * (1 << 16));

				for (int i = 0; i < data.size(); i += 4) {
					int red, green, blue;

					int cb = quint8(data.at(i)) - 128;
					int y1 = quint8(data.at(i + 1));
					int cr = quint8(data.at(i + 2)) - 128;
					int y2 = quint8(data.at(i + 3));

					red = y1 + (k13 * cr >> 16);
					green = y1 - (k22 * cb >> 16) - (k23 * cr >> 16);
					blue = y1 + (k32 * cb >> 16);

					saturate(red, 0, 255);
					saturate(green, 0, 255);
					saturate(blue, 0, 255);

					pixels.append(qRgb(red, green, blue));

					red = y2 + (k13 * cr >> 16);
					green = y2 - (k22 * cb >> 16) - (k23 * cr >> 16);
					blue = y2 + (k32 * cb >> 16);

					saturate(red, 0, 255);
					saturate(green, 0, 255);
					saturate(blue, 0, 255);

					pixels.append(qRgb(red, green, blue));
				}
			}
			break;
	}

	return pixels;
}

void ov7670::saturate(int &value, int min, int max)
{
	if (value < min)
		value = min;
	else if (value > max)
		value = max;
}

void ov7670::display(QByteArray incomingData)
{
	if (incomingData.size() != image->height() * image->width() * 2) {
		statusBar()->showMessage("Invalid size of image!", 2000 );
		return;
	}
	QVector<QRgb> pixels = decode(incomingData);
	for (int j = 0; j < image->height(); j++) {
		for (int i = 0; i < image->width(); i++) {
			image->setPixel(i, j, pixels.at(j * image->width() + i));
		}
	}
	camera_win->showimage(image);
}

void ov7670::send_packet(unsigned char addr, unsigned char cmd, QByteArray data) {
	QByteArray packet;
	unsigned char tx_crc = 0xFF;
	tx_crc = crc8Table[tx_crc ^ FEND];
	tx_crc = crc8Table[tx_crc ^ addr];
	tx_crc = crc8Table[tx_crc ^ cmd];
	tx_crc = crc8Table[tx_crc ^ data.size()];
	foreach (unsigned char k, data) {
		tx_crc = crc8Table[tx_crc ^ k];
	}

	packet.append(addr); // Addr
	packet.append(cmd); // CMD
	packet.append(data.size()); // N
	packet.append(data); // data
	packet.append(tx_crc); // CRC
	packet = wake_stuffbyte(packet);
	packet.prepend(FEND); // FEND

	tx_queue.enqueue(packet);
	packet.clear();
}

void ov7670::send_queue() {
	if(!tx_queue.isEmpty() && sending == 0) {
		//send_queue_timer->start(300);
		serialPort->write(tx_queue.dequeue());
		sending = 0;
	}
}

void ov7670::autoget_timeout() {
	if(serialdata.size() == image->height() * image->width() * 2) {
		on_pbParseImage_clicked(); // parse
		on_pbGetImage_clicked(); // Get new frame
	} else if (serialdata.size() == 0) {
		on_pbGetImage_clicked();
	}
}
void ov7670::on_pbSend_clicked()
{
	message.clear();
	message.append(201);
	message.append(2);
	message.append(ui->leparam->text().toInt(0,16));
	message.append(ui->levalue->text().toInt(0,16));
	send_packet(201,2,message);
	message.clear();
}
void ov7670::on_pbAutoGet_clicked()
{
	on_pbGetImage_clicked();
	autoget_timer->start(200);
}

void ov7670::on_pbAutoGetStop_clicked()
{
	autoget_timer->stop();
}
void ov7670::on_pbGetImage_clicked()
{
//	T1_timer->stop();
//	serialPort->write("1\r\n");
	QByteArray tx_data;
	tx_data.append(0x0F);
	send_packet(201,1,tx_data);
	tx_data.clear();
}
void ov7670::on_pbClear_clicked()
{
	for (int j = 0; j < image->height(); j++) {
		for (int i = 0; i < image->width(); i++) {
			image->setPixel(i, j, 255);
		}
	}
	camera_win->showimage(image);
	serialdata.clear();
	ui->loadpercent->setValue(serialdata.size());
}

void ov7670::on_pbParseImage_clicked()
{
	display(serialdata);
	serialdata.clear();
	ui->loadpercent->setValue(serialdata.size());
}

void ov7670::on_pbCameraShow_clicked()
{
	camera_win->show();
}

void ov7670::on_pbSettings_clicked()
{
	options_win->show();
}

void ov7670::on_hsServo_sliderMoved(int position)
{
	ui->lbServo->setText(QString::number(position));
	message.clear();
	message.append(position);
	serialPort->write(message);
}

void ov7670::on_hsServo_valueChanged(int value)
{
	on_hsServo_sliderMoved(value);
}
QByteArray ov7670::wake_stuffbyte(QByteArray packet) {
	QByteArray stuffed_packet;
	foreach (unsigned char byte, packet) {
		switch (byte) {
			case FEND:
				stuffed_packet.append(FESC);
				stuffed_packet.append(TFEND);
				break;
			case FESC:
				stuffed_packet.append(FESC);
				stuffed_packet.append(TFESC);
				break;
			default:
				stuffed_packet.append(byte);
				break;
		}
	}
	return stuffed_packet;
}
QByteArray ov7670::wake_stuffbyte(unsigned char packet) {
	QByteArray stuffed_packet;
	switch (packet) {
		case FEND:
			stuffed_packet.append(FESC);
			stuffed_packet.append(TFEND);
			break;
		case FESC:
			stuffed_packet.append(FESC);
			stuffed_packet.append(TFESC);
			break;
		default:
			stuffed_packet.append(packet);
			break;
	}
	return stuffed_packet;
}
