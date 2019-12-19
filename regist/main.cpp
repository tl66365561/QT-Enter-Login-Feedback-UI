
#include "Mydesign.h"
#include "database.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//MainWindow w;
	//w.show();


	DataBase d;
	d.createConnection();  //创建连接
	d.createTable();
	d.insert();
	d.queryAll();          //已经完成过createTable(), insert(), 现在进行查询
	
	return a.exec();
}
