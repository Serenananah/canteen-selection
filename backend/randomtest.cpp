// randomtest.cpp
#include "include/DBOperation.h"
#include "utils/RandomSelector.h"
#include <iostream>
#include <cstdlib> // 用于 rand() 和 srand()
#include <ctime>   // 用于 time()
#include <vector>
#include <tuple>

// 假设 DBOperations 类已经提供了 fetchAllStalls 和 fetchAllDishes 方法
// 假设 RandomSelector 类已经提供了 randomStallName 和 randomDishInfo 方法

int main() {
    // 初始化随机数种子
    srand(static_cast<unsigned int>(time(0)));

    // 创建数据库操作对象
    DBOperations dbOps;
    
    // 创建随机选择器对象，只传入数据库操作对象的引用
    RandomSelector randomSelector(dbOps);

    try {
        // 测试随机选择摊位功能
        std::string stallName = randomSelector.randomStallName();
        std::cout << "Randomly selected stall name: " << stallName << std::endl;

        // 测试随机选择菜品功能
        auto [dishName, price] = randomSelector.randomDishInfo();
        std::cout << "Randomly selected dish: " << dishName << " with price: " << price << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}