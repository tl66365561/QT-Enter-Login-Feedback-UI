


#include "database.h"
#include <QVariant>


//
////建立一个数据库连接
//bool DataBase::createConnection()
//{
//	//以后就可以用"sqlite1"与数据库进行连接了
//	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "sqlite1");
//	db.setDatabaseName(".//qtDBtest.db");
//	if( !db.open())
//	{
//		qDebug() << "无法建立数据库连接";
//		return false;
//	}
//	return true;
//}
//
////创建数据库表
//	bool DataBase::createTable()
//{
//	QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
//	QSqlQuery query(db);
//	bool success = query.exec("create table stu(id int primary key,age int)");
//	if(success)
//	{
//		qDebug() << QObject::tr("sucessed create！\n");
//		return true;
//	}
//	else
//	{
//		qDebug() << QObject::tr("error create！\n");
//		return false;
//	}
//}
//
//	//向数据库中插入记录
//	bool DataBase::insert()
//	{
//		QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
//		QSqlQuery query(db);
//		query.prepare("insert into stu values(:a, :b)");
//
//
//		/*query.prepare("INSERT INTO person (id, forename, surname) "
//		"VALUES (:id, :forename, :surname)");
//		query.bindValue(":id", 1001);
//		query.bindValue(":forename", "Bart");
//		query.bindValue(":surname", "Simpson");
//		query.exec();*/
//
//			query.bindValue(":a",16060102113);
//			query.bindValue(":b", 20);
//		
//
//			bool success=query.exec();
//			if(!success)
//			{
//				QSqlError lastError = query.lastError();
//				qDebug() << lastError.driverText() << QString(QObject::tr("insert error"));
//				return false;
//			}
//		return true;
//	}
//
//	//查询所有信息
//	bool DataBase::queryAll()
//	{
//		QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
//		QSqlQuery query(db);
//		query.exec("select * from stu");
//		QSqlRecord rec = query.record();
//		qDebug() << QObject::tr("stu count ：" ) << rec.count();
//
//		while(query.next())
//		{
//			for(int index = 0; index < 10; index++)
//				qDebug() << query.value(index) << " ";
//			qDebug() << "\n";
//		}
//		return true;
//	}
//
//	//根据ID删除记录
//	bool DataBase::deleteById(int id)
//	{
//		QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
//		QSqlQuery query(db);
//		query.prepare(QString("delete from stu where id = %1").arg(id));
//		if(!query.exec())
//		{
//			qDebug() << "删除记录失败！";
//			return false;
//		}
//		return true;
//	}
//
//	//根据ID更新记录
//	bool DataBase::updateById(int id)
//	{
//		QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
//		QSqlQuery query(db);
//		query.prepare(QString("update stu set attribute=?,type=?,"
//			"kind=?, nation=?,"
//			"carnumber=?, elevaltor=?,"
//			"distance=?, oil=?,"
//			"temperature=? where id=%1").arg(id));
//
//		query.bindValue(0,"四轮");
//		query.bindValue(1,"轿车");
//		query.bindValue(2,"富康");
//		query.bindValue(3,rand()%100);
//		query.bindValue(4,rand()%10000);
//		query.bindValue(5,rand()%300);
//		query.bindValue(6,rand()%200000);
//		query.bindValue(7,rand()%52);
//		query.bindValue(8,rand()%100);
//
//		bool success=query.exec();
//		if(!success)
//		{
//			QSqlError lastError = query.lastError();
//			qDebug() << lastError.driverText() << QString(QObject::tr("更新失败"));
//		}
//		return true;
//	}
//
//	//排序
//	bool DataBase::sortById()
//	{
//		QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
//		QSqlQuery query(db);
//		bool success=query.exec("select * from automobil order by id desc");
//		if(success)
//		{
//			qDebug() << QObject::tr("排序成功");
//			return true;
//		}
//		else
//		{
//			qDebug() << QObject::tr("排序失败！");
//			return false;
//		}
//	}
//


DataBase::DataBase(){

}





void DataBase::initsql(){

	
	if (QSqlDatabase::contains("first"))
	{
		db = QSqlDatabase::database("first");
	}
	else
	{
		db = QSqlDatabase::addDatabase("QSQLITE","First");
		db.setDatabaseName("MyDataBase1.db");
		//db.setUserName("tonglin");
		//db.setPassword("123456");
	}



	if(db.open())
	{
		qDebug()<<"Database connected successfully!";
		return;
	}
	else
	{
		qDebug()<<"Database connected failed!";
		return;
	}


	


}



bool DataBase::Search(QString s1,QString s2){

	//在数据库中检索s1对应的结果串，然后与s2进行比对

	//select pwd from UserInfo where usr=s1;
	
	QSqlQuery sql_query(db);
	QString search_sql="select password from UserInfo where username=(?)";
	sql_query.prepare(search_sql);
	sql_query.addBindValue(s1);

	if(!sql_query.exec())
	{
		qDebug() << "Error: Fail to Search." << sql_query.lastError();
	}
	else
	{
		qDebug() << "Search Success !";
	}



	//报错： QSqlQuery::value: not positioned on a valid record
	QString pass;

     if(sql_query.next()){
	 pass = sql_query.value(0).toString();
	 }


	 /*QSqlRecord rec = sql_query.record();
	 int snamecol = rec.indexOf(s1);
	 QString value = sql_query.value(snamecol).toString();*/
	
	
	if(s2==pass)
	{
		return true;
	}
	else
	{
		return false;


	}
}


void DataBase::createtable(){
	
	QSqlQuery sql_query(db);

	QString create_sql = "create table UserInfo( username varchar(20),password varchar(20))";
	sql_query.prepare(create_sql);
	if(!sql_query.exec())
	{
		qDebug() << "Error: Fail to create table." << sql_query.lastError();
	}
	else
	{
		qDebug() << "Table created!";
	}

	
	//query->exec("create table UserInfo(username int(20),password int(20)");
	//db.close();
}


//Driver not load原因： 是因为QSQLQuery对象没有和db关联

void DataBase::insert(QString Usr,QString Pwd){

	QSqlQuery sql_query(db);
	QString insert_sql = "insert into UserInfo values (?, ?)";
	sql_query.prepare(insert_sql);
	sql_query.addBindValue(Usr);
	sql_query.addBindValue(Pwd);
	if(!sql_query.exec())
	{
		qDebug() << sql_query.lastError();
	}
	else
	{
		qDebug() << "inserted Wang!";
	}
	if(!sql_query.exec("INSERT INTO student VALUES(3, \"Li\", 23)"))
	{
		qDebug() << sql_query.lastError();
	}
	else
	{
		qDebug() << "inserted Li!";
	}

	

}




DataBase::~DataBase(){

	db.close();
}

