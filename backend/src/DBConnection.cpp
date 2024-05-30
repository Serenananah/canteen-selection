// backend/src/DBConnection.cpp
#include "DBConnection.h"
#include <cppconn/exception.h>

DBConnection::DBConnection() {
    driver = sql::mysql::get_mysql_driver_instance();
    conn = driver->connect("tcp://127.0.0.1:3306", "root", "Angel20050407#"); // 替换为您的数据库用户名和密码
    conn->setSchema("canteen_system");
}

DBConnection::~DBConnection() {
    delete conn;
}

sql::Connection* DBConnection::getConnection() {
    return conn;
}