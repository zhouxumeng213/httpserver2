#include"mysql_connect.h"
using namespace std;
sql_connect::sql_connect(const string &)
	:_host(host),_user(user),_passwd(passwd),_db(db)
{
	_mysql_base=mysql_init(NULL);
}
sql_connect::sql_connect()
{
	cout<<"constrect"<<endl;
}
sql_connect::~sql_connect()
{
	close_mysql();
	cout<<"~constrect"<<endl;
}
bool sql_connect::connect_mysql()
{
	if(!mysql_real_connect(_mysql_base,_host.c_str(),_user.c_str(),_passwd.c_str(),_db.c_str(),3306,NULL,0)){
		cerr<<"connect error"<<endl;
		return false;
	}
	cout<<"connect success"<<endl;
	return true;
}
bool sql_connect::insert_info(const string& _info)
{
	string sql_cmd="INSERT INTO STUDENTS() VALUES "
	sql_cmd+="(";
	sql_cmd+=_info;
	sql_cmd+=")";
	if(mysql_query(_mysql_base,sql_cmd)==0){
		cout<<"insert success"<<endl;
		return true;
	}else{
		cout<<"insert failed"<<endl;
		return false;
	}
}
bool sql_connect::close_mysql()
{
	mysql_close(_mysql_base);
}
#ifdef _DEBUG_
int main()
{
	sql_connect _conn;
	_conn.connect_mysql();
	_conn.insert_info();
	cout<<""<<mysql_get_client_info()<<endl;
	return 0;
}
