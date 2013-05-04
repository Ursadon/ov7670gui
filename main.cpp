#include "ov7670.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ov7670 w;
	w.show();
	
	return a.exec();
}
