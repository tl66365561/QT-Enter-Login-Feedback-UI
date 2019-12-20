#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QWidget>
#include<QDesktopServices>
#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include<QLabel>
#include<QLineEdit>
#include "database.h"


class LoginForm: public QDialog{

Q_OBJECT 

public:
	explicit LoginForm(QDialog *parent = 0);  //explicit 防止歧义
	~LoginForm();
	

public slots:
	void true_();//点击确认按钮后执行的槽函数 


private:

//	QLabel *infolable;         //居中显示“注册界面”字样
	QLabel *usrlable;         //"用户名"标签
	QLabel *pwdLable;              //"密码"标签
	QLineEdit *usrLEd;      //用户名编辑行
	QLineEdit *pwdLEd;           //密码编辑行
	QPushButton *TrueBtn;        //确认按钮
	QPushButton *FalseBtn;       //取消按钮
	QMessageBox* messageBox;

	DataBase *Mydb;

};



#endif  
