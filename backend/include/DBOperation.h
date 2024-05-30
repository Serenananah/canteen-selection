// 数据库处理
#ifndef DBOPERATIONS_H
#define DBOPERATIONS_H

#include "DBConnection.h"
#include <vector>
#include <string>

class DBOperations {
public:
    DBOperations();
    std::vector<std::vector<std::string>> fetchAllCanteens();
    std::vector<std::vector<std::string>> fetchStallsByCanteen(int canteen_id);
    std::vector<std::vector<std::string>> fetchDishesByStall(int stall_id);
private:
    DBConnection db;
};

#endif 