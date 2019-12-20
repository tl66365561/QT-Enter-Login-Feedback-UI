#include "enter.h"

EnterForm::EnterForm(QDialog *parent) :
QDialog(parent)
{
	//设置窗体标题
	this->setWindowTitle(tr("Enter UI"));

	//用户名Label
	//userNameLbl->setMargin(20);
	userNameLbl = new QLabel(this);   //new一个标签对象
	userNameLbl->setMargin(20);
	userNameLbl->move(70,80);         //移动到(70,80)位置(Label左上角坐标，相对于父窗体)
	userNameLbl->setText("UserName:");  //设置标签文本

	//用户名输入框
	userNameLEd = new QLineEdit(this);
	userNameLEd->move(120,80);
	userNameLEd->setPlaceholderText(tr("Please input UserName!"));//占位符

	//密码Label
	pwdLbl = new QLabel(this);
	pwdLbl->move(80,130);
	pwdLbl->setMargin(20);
	pwdLbl->setText("PassWord:");

	//密码输入框
	pwdLEd = new QLineEdit(this);
	pwdLEd->move(120,130);
	pwdLEd->setPlaceholderText("Please input PassWord!");
	pwdLEd->setEchoMode(QLineEdit::Password);//输入的密码以圆点显示

	//登录按钮
	loginBtn = new QPushButton(this);
	loginBtn->move(80,200);
	loginBtn->setText("Enter");

	//退出按钮
	exitBtn = new QPushButton(this);
	exitBtn->move(170,200);
	exitBtn->setText("Quit");

	//单击登录按钮时 执行 LoginForm::login 槽函数(自定义)；单击退出按钮时 执行 LoginForm::close 槽函数(窗体的关闭函数，不用自己写)
	connect(loginBtn,SIGNAL(clicked()),this,SLOT(enter_()));
	connect(exitBtn,SIGNAL(clicked()),this,SLOT(close()));

	Mydb=new DataBase();
	Mydb->initsql();  

	this->show();
}




void EnterForm::enter_()
{
	//获得userNameLEd输入框的文本：userNameLEd->text()；
	//trimmed()去掉前后空格
	//tr()函数，防止设置中文时乱码

	//userNameLEd->text().trimmed() == tr("tonglin") && pwdLEd->text() == tr("123456")
	QString s1=userNameLEd->text().trimmed();
	QString s2=pwdLEd->text();

	if(Mydb->Search(s1,s2))             //添加数据库之后，这边需要搞一个Search去判断是否在数据库中
	{
		
		//内存泄漏
		messageBox = new QMessageBox(this);
		messageBox->setIcon(QMessageBox::Information);
		messageBox->setWindowTitle(" Hello !! ");
		messageBox->setText("Welcome to coming ...");
		messageBox->show();
		
		
		
		//accept();//关闭窗体，并设置返回值为Accepted
	} 
	else 
	{                              //标题              内容                OK按钮  
		QMessageBox::warning(this, tr("Warning！"),tr("Input Error！"),QMessageBox::Yes);

		// 清空输入框内容
		userNameLEd->clear();
		pwdLEd->clear();

		//光标定位
		userNameLEd->setFocus();
	}
}



EnterForm::~EnterForm(){

	delete messageBox;
	delete Mydb;
	delete userNameLbl;        
	delete pwdLbl;             
	delete userNameLEd;     
	delete pwdLEd;          
	delete loginBtn;      
	delete exitBtn;       
}	