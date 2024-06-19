// 数据库处理
#ifndef DBOPERATIONS_H
#define DBOPERATIONS_H

#include "DBConnection.h"
#include <vector>
#include <string>

class DBOperations {
public:
    DBOperations();
    ~DBOperations(); // 确保析构函数在这里声明
    //以下是一系列获取数据函数
    std::vector<std::vector<std::string>> fetchAllCanteens();
    std::vector<std::vector<std::string>> fetchStallsByCanteen(int canteen_id);
    std::vector<std::vector<std::string>> fetchDishesByStall(int stall_id);
    // 新增方法
    std::vector<std::vector<std::string>> fetchAllStalls(); // 获取所有摊位信息
    std::vector<std::vector<std::string>> fetchAllDishes(); // 获取所有菜品信息
private:
    DBConnection db;
};

#endif 