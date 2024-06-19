// backend/src/DBOperations.cpp
#include "../include/DBOperation.h"
#include <cppconn/prepared_statement.h>

DBOperations::DBOperations() : db() {}

DBOperations::~DBOperations() {
    // 确保在对象销毁前关闭数据库连接
    if (db.getConnection()) {
        db.getConnection()->close();
    }
}

std::vector<std::vector<std::string>> DBOperations::fetchAllCanteens() {
    sql::Connection* conn = db.getConnection();
    sql::Statement* stmt = conn->createStatement();
    sql::ResultSet* res = stmt->executeQuery("SELECT * FROM canteens");

    std::vector<std::vector<std::string>> result;
    while (res->next()) {
        std::vector<std::string> row;
        row.push_back(res->getString("canteen_id"));
        row.push_back(res->getString("name"));
        result.push_back(row);
    }
    delete res;
    delete stmt;
    return result;
}

std::vector<std::vector<std::string>> DBOperations::fetchStallsByCanteen(int canteen_id) {
    sql::Connection* conn = db.getConnection();
    sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT * FROM stalls WHERE canteen_id = ?");
    pstmt->setInt(1, canteen_id);
    sql::ResultSet* res = pstmt->executeQuery();

    std::vector<std::vector<std::string>> result;
    while (res->next()) {
        std::vector<std::string> row;
        row.push_back(res->getString("stall_id"));
        row.push_back(res->getString("name"));
        result.push_back(row);
    }
    delete res;
    delete pstmt;
    return result;
}

std::vector<std::vector<std::string>> DBOperations::fetchDishesByStall(int stall_id) {
    sql::Connection* conn = db.getConnection();
    sql::PreparedStatement* pstmt = conn->prepareStatement("SELECT * FROM dishes WHERE stall_id = ?");
    pstmt->setInt(1, stall_id);
    sql::ResultSet* res = pstmt->executeQuery();

    std::vector<std::vector<std::string>> result;
    while (res->next()) {
        std::vector<std::string> row;
        row.push_back(res->getString("dish_id"));
        row.push_back(res->getString("name"));
        row.push_back(res->getString("price"));
        row.push_back(res->getString("queue_length"));
        result.push_back(row);
    }
    delete res;
    delete pstmt;
    return result;
}

// 实现新增的fetchAllStalls方法
std::vector<std::vector<std::string>> DBOperations::fetchAllStalls() {
    sql::Connection* conn = db.getConnection();
    sql::Statement* stmt;
    sql::ResultSet* res;
    std::vector<std::vector<std::string>> result;

    try {
        stmt = conn->createStatement();
        res = stmt->executeQuery("SELECT stall_id, stall_name FROM Stalls");
        while (res->next()) {
            std::vector<std::string> row;
            row.push_back(res->getString("stall_id"));
            row.push_back(res->getString("stall_name"));
            result.push_back(row);
        }
    } catch (sql::SQLException& e) {
        std::cerr << "SQL Exception in fetchAllStalls: " << e.what() << std::endl;
    }

    delete res;
    delete stmt;
    return result;
}

// 实现新增的fetchAllDishes方法
std::vector<std::vector<std::string>> DBOperations::fetchAllDishes() {
    sql::Connection* conn = db.getConnection();
    sql::Statement* stmt;
    sql::ResultSet* res;
    std::vector<std::vector<std::string>> result;

    try {
        stmt = conn->createStatement();
        res = stmt->executeQuery("SELECT dish_id, dish_name, price FROM Dishes");
        while (res->next()) {
            std::vector<std::string> row;
            row.push_back(res->getString("dish_id"));
            row.push_back(res->getString("dish_name"));
            row.push_back(res->getString("price")); // 假设price是字符串类型
            result.push_back(row);
        }
    } catch (sql::SQLException& e) {
        std::cerr << "SQL Exception in fetchAllDishes: " << e.what() << std::endl;
    }

    delete res;
    delete stmt;
    return result;
}