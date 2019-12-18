#ifndef REGIST_H
#define REGIST_H

#include <QtGui/QMainWindow>
#include "ui_regist.h"

class regist : public QMainWindow
{
	Q_OBJECT

public:
	regist(QWidget *parent = 0, Qt::WFlags flags = 0);
	~regist();

private:
	Ui::registClass ui;
};

#endif // REGIST_H
