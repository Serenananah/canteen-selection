//数据库连接
#ifndef DBCONNECTION_H
#define DBCONNECTION_H

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>

class DBConnection {
public:
    DBConnection();
    ~DBConnection();
    sql::Connection* getConnection();
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* conn;
};

#endif // DBCONNECTION_H