// main.cpp
#include "backend/include/DBConnection.h"
#include <iostream>

int main() {
    try {
        DBConnection dbConn;
        sql::Connection* conn = dbConn.getConnection();
        std::cout << "Connected to database successfully!" << std::endl;
        // You can add more database operations here
    } catch (sql::SQLException &e) {
        std::cerr << "SQL error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}