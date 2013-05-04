#ifndef OPTIONSUI_H
#define OPTIONSUI_H

#include <QDialog>

namespace Ui {
	class optionsui;
}

class OptionsWindow : public QDialog
{
		Q_OBJECT
		
	public:
		explicit OptionsWindow(QWidget *parent = 0);
		~OptionsWindow();
		
	private:
		Ui::optionsui *ui;
};

#endif // OPTIONSUI_H
