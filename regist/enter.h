
#ifndef ENTER_H
#define ENTER_H


#include <QMainWindow>
#include <QWidget>
#include<QDesktopServices>
#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include<QLabel>
#include<QLineEdit>
#include "database.h"


class EnterForm : public QDialog
{
	Q_OBJECT 
public:
	explicit EnterForm(QDialog *parent = 0);  //explicit 防止歧义
	~EnterForm();

public slots:
		void enter_();//点击登录按钮是执行的槽函数
	
private:
	QLabel *userNameLbl;         //"用户名"标签
	QLabel *pwdLbl;              //"密码"标签
	QLineEdit *userNameLEd;      //用户名编辑行
	QLineEdit *pwdLEd;           //密码编辑行
	QPushButton *loginBtn;       //登录按钮
	QPushButton *exitBtn;        //退出按钮
	QMessageBox *messageBox;

	DataBase *Mydb;


};








//class Enter{
//
//public:
//	Enter();
//	~Enter();
//	void run();
//
//
//private:
//
//
//
//};
//
//
//
//
//
#endif