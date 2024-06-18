// backend/src/DBConnection.cpp
#include "../include/DBConnection.h"
#include <cppconn/exception.h>

DBConnection::DBConnection() {
    driver = sql::mysql::get_mysql_driver_instance();
    conn = driver->connect("tcp://127.0.0.1:3306", "root", "Angel20050407#"); 
    conn->setSchema("CanteenDB");
}

DBConnection::~DBConnection() {
    delete conn;
}

sql::Connection* DBConnection::getConnection() {
    return conn;
}