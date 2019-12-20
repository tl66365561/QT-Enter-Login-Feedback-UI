

#include"login.h"



LoginForm::LoginForm(QDialog *parent):	
					 QDialog(parent)
					,messageBox(nullptr)

{

	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));   

	//设置窗体标题
	this->setWindowTitle("注册界面");


	/*infolable=new QLabel(this);
	infolable->move(130,40);
	infolable->setText("注册界面 ");*/

	
	//userNameLbl->setMargin(20);
	usrlable = new QLabel(this);   //new一个标签对象
	
	usrlable->setMargin(20);
	usrlable->move(20,60);         //移动到(70,80)位置(Label左上角坐标，相对于父窗体)
	usrlable->setText("用户ID:");  //设置标签文本
	//usrlable->setFrameShadow(QFrame::Plain);
	//usrlable->setFrameShape(QFrame::StyledPanel);


	//用户名输入框
	usrLEd = new QLineEdit(this);
	usrLEd->move(110,80);
	usrLEd->setPlaceholderText(tr("Please input UserName!"));//占位符

	//密码Label
	pwdLable = new QLabel(this);
	pwdLable->move(20,110);
	pwdLable->setMargin(20);
	pwdLable->setText("密码:");

	//密码输入框
	pwdLEd = new QLineEdit(this);
	pwdLEd->move(110,130);
	pwdLEd->setPlaceholderText("Please input PassWord!");
	pwdLEd->setEchoMode(QLineEdit::Password);//输入的密码以圆点显示

	//确认按钮
	TrueBtn = new QPushButton(this);
	TrueBtn->move(60,200);
	TrueBtn->setText("确认");

	//退出按钮
	FalseBtn = new QPushButton(this);
	FalseBtn->move(190,200);
	FalseBtn->setText("取消");

	//单击登录按钮时 执行 LoginForm::login 槽函数(自定义)；单击退出按钮时 执行 LoginForm::close 槽函数(窗体的关闭函数，不用自己写)
	connect(TrueBtn,SIGNAL(clicked()),this,SLOT(true_()));
	connect(FalseBtn,SIGNAL(clicked()),this,SLOT(close()));



	Mydb=new DataBase();
	Mydb->initsql();  
	this->show();
}

void LoginForm::true_(){   //将注册信息插入到关联数据库
    
	     

    //获得用户在编辑行中输入的内容
	QString s1=usrLEd->text();
	QString s2=pwdLEd->text();
	Mydb->insert(s1,s2);   //数据未插入？？？
	


	//弹窗提示注册成功				 	
	messageBox = new QMessageBox(this);
	messageBox->setIcon(QMessageBox::Information);
	messageBox->setWindowTitle(" Login Success !! ");
	messageBox->setText("congratulation ! !");
	messageBox->show();
	

}

LoginForm::~LoginForm(){

	delete Mydb;
	//delete infolable;       
	delete usrlable;        
	delete pwdLable;        
	delete usrLEd;      
	delete pwdLEd;       
	delete TrueBtn;    
	delete FalseBtn;

	if(messageBox)
		delete messageBox;

}






