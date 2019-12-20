
#include "Mydesign.h"
#include "database.h"
#include <QtGui/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	DataBase d;
	d.initsql();
	d.createtable();

	MainWindow w;
    w.show();
	return a.exec();
}






//问题：

//1.提示标签的全显示处理...

//2.登陆界面添加背景图...            怎么设置背景图平铺而不是叠加方式
//QPalette pa;
//QPixmap pixmap(":/image/image/jiemian.png"); // 资源文件路径
//pa.setBrush(this->backgroundRole(), QBrush(pixmap));
//this->setPalette(pa);

//3.程序执行一次就中断...      delete释放了分配的地址  delete之前判空

//4.数据库的连接操作...


//5.中文乱码  编码格式的问题  输入法的编码格式和编辑器的编码格式？？？？？？？？？？？？？？？  
//6.文本标签不能正常显示在框的左边    