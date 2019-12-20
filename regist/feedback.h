#ifndef FEEDBACK_H
#define FEEDBACK_H

#include <QMainWindow>
#include <QWidget>
#include<QDesktopServices>
#include<QUrl>
#include<windows.h>

class FeedbackForm :public QMainWindow{

	Q_OBJECT 
public:
	explicit FeedbackForm(QWidget* parent=0);  //explicit 防止歧义
	~FeedbackForm();




};








#endif