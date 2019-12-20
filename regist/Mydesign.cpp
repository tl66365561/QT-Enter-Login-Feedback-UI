
#include "Mydesign.h"

MainWindow::MainWindow(QWidget *parent):
						QMainWindow(parent)
							,en(nullptr)
							,fe(nullptr)
						    ,lo(nullptr){
	
	
	
	//QPalette pa;
	//QPixmap pixmap(":/regist/doc-open"); // 资源文件路径
	//pa.setBrush( QPalette::Background, QBrush(pixmap));
	//this->setPalette(pa);

	//设置界面的背景
	this->setStyleSheet("QMainWindow{border-image:url(:/regist/doc-open)}");

	//控制中文格式的显示
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));  



	infolable=new QLabel(this);
	//infolable->move(200,50);
	infolable->setText( "用户登陆系统");
	//infolable->setMargin(3);
	infolable->setAlignment(Qt::AlignCenter);
	infolable->setStyleSheet("color: green");
	


	this->setFixedSize(900, 700);
	this->setWindowTitle("欢迎进入用户登录管理系统");
	enterBtn = new QPushButton(this);
	loginBtn = new QPushButton(this);
	feedbackBtn = new QPushButton(this);	
	//Layout

    //QString text = QString::fromUtf16(L"登录");
	//QString str1("你好");
	//QByteArray bLocal = str1.toLocal8Bit(); // 受setCodecForLocale影响，会转换为设定的编码。如果本机不支持指定编码，则会按toLatin1处理
	//QString bUtf8 = str1.toUtf8();       // 不受setCodecForLocale影响，强制转换为UTF-8编码
	//qDebug() << str1;                       // 正常，Qt会将UTF-16转换为UTF-8输出
	//qDebug() << bLocal;                     // 乱码，用UTF-8编码输出GBK字节流
	//qDebug() << bUtf8;                      // 正常，用UTF-8编码输出UTF-8字节流
	//QString text;
	//text = bUtf8;

	enterBtn->move(400,100);
	enterBtn->setText("登录");
	loginBtn->move(400,200);
	loginBtn->setText("注册");
	feedbackBtn->move(400,300);
	feedbackBtn->setText("反馈");


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
	if(en)
		delete en;
	if(fe)
		delete fe;
	if(lo)
		delete lo;
	
	delete infolable; 
	delete enterBtn;       
	delete loginBtn;       
	delete feedbackBtn;    
}


