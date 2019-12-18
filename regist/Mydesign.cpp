

#include "Mydesign.h"


MainWindow::MainWindow(QWidget *parent):
QMainWindow(parent){

	this->setFixedSize(900, 700);
	this->setWindowTitle("UI");
	enterBtn = new QPushButton(this);
	loginBtn = new QPushButton(this);
	feedbackBtn = new QPushButton(this);	
	//Layout
	enterBtn->move(400,100);
	enterBtn->setText("Enter");
	loginBtn->move(400,200);
	loginBtn->setText("Login");
	feedbackBtn->move(400,300);
	feedbackBtn->setText("Feedback");


	connect(enterBtn,SIGNAL(clicked()),this,SLOT(enter()));
	connect(feedbackBtn,SIGNAL(clicked()),this,SLOT(feedback()));




}



void MainWindow::enter(){

	en=new EnterForm();


}
void MainWindow::feedback(){


	fe=new FeedbackForm();

}


MainWindow::~MainWindow(){

delete en;
delete fe;

}


