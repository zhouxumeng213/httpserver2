#pragma once
#include<iostream>
#include<mysql.h>
#include<string.h>
using namespace std;
class sql_connect{
	public:
		sql_connect();
		~sql_connect();

		bool _connect_mysql();
		bool _close_mysql();
	private:
		MYSQL *mysql_base;
		string _host;
		string _user;
		string _passwd;
		string db;
};
