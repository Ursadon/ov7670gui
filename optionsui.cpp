#include "optionsui.h"
#include "ui_optionsui.h"

OptionsWindow::OptionsWindow(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::optionsui)
{
	ui->setupUi(this);
}

OptionsWindow::~OptionsWindow()
{
	delete ui;
}
