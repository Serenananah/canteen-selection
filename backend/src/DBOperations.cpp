// backend/src/DBOperations.cpp
#include "DBOperations.h"
#include <cppconn/prepared_statement.h>

DBOperations::DBOperations() : db() {}

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