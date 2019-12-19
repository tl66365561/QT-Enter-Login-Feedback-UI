
#include "Mydesign.h"

MainWindow::MainWindow(QWidget *parent):
QMainWindow(parent){
	
	
	//设置界面的背景
	

	QPalette pa;
	QPixmap pixmap(":/regist/doc-open"); // 资源文件路径
	pa.setBrush( QPalette::Background, QBrush(pixmap));
	this->setPalette(pa);


	//this->setStyleSheet("border-image:url(/:regist/doc-open);");

	infolable=new QLabel(this);
	//infolable->move(200,50);
	infolable->setText( "Land System");
	//infolable->setMargin(3);
	infolable->setAlignment(Qt::AlignCenter);
	infolable->setStyleSheet("color: green");
	



	this->setFixedSize(900, 700);
	this->setWindowTitle("UI");
	enterBtn = new QPushButton(this);
	loginBtn = new QPushButton(this);
	feedbackBtn = new QPushButton(this);	
	//Layout
	enterBtn->move(400,100);
	enterBtn->setText("登录");
	loginBtn->move(400,200);
	loginBtn->setText("Login");
	feedbackBtn->move(400,300);
	feedbackBtn->setText("Feedback");


	connect(enterBtn,SIGNAL(clicked()),this,SLOT(enter()));
	connect(feedbackBtn,SIGNAL(clicked()),this,SLOT(feedback()));
	connect(loginBtn,SIGNAL(clicked()),this,SLOT(login()));




}



void MainWindow::enter(){

	en=new EnterForm();


}

void MainWindow::login(){

	lo=new LoginForm();
	

}


void MainWindow::feedback(){


	fe=new FeedbackForm();

}


MainWindow::~MainWindow(){

delete en;
delete fe;
delete lo;
}


