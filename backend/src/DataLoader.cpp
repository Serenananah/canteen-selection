#include "DataLoader.h"
#include <iostream>

DataLoader::DataLoader(DBConnection* dbConn) : dbConn(dbConn) {}

void DataLoader::loadCanteenData(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, name;
        std::getline(ss, id, ',');
        std::getline(ss, name, ',');
        std::string query = "INSERT INTO canteens (canteen_id, name) VALUES (" + id + ", '" + name + "')";
        executeQuery(query);
    }
}

void DataLoader::loadStallData(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, canteenId, name;
        std::getline(ss, id, ',');
        std::getline(ss, canteenId, ',');
        std::getline(ss, name, ',');
        std::string query = "INSERT INTO stalls (stall_id, canteen_id, name) VALUES (" + id + ", " + canteenId + ", '" + name + "')";
        executeQuery(query);
    }
}

void DataLoader::loadDishData(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, stallId, name, price, queueLength;
        std::getline(ss, id, ',');
        std::getline(ss, stallId, ',');
        std::getline(ss, name, ',');
        std::getline(ss, price, ',');
        std::getline(ss, queueLength, ',');
        std::string query = "INSERT INTO dishes (dish_id, stall_id, name, price, queue_length) VALUES (" + id + ", " + stallId + ", '" + name + "', " + price + ", " + queueLength + ")";
        executeQuery(query);
    }
}

void DataLoader::executeQuery(const std::string& query) {
    try {
        sql::Statement* stmt = dbConn->getConnection()->createStatement();
        stmt->execute(query);
        delete stmt;
    } catch (sql::SQLException& e) {
        std::cerr << "SQL error: " << e.what() << std::endl;
    }
}
