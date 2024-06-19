// RandomSelector.cpp
#include "RandomSelector.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <iostream>

// 构造函数，初始化随机数种子
RandomSelector::RandomSelector(DBOperations& pdbOps):dbOps(pdbOps){
    srand(time(0));
}

// 实现转盘随机选择菜品的功能
Dish RandomSelector::spin(double minPrice, double maxPrice, const std::string& category) {
    std::vector<Dish> filteredDishes;

    // 筛选符合条件的菜品
    for (auto& canteen : canteens) {
        for (auto& stall : canteen.getStalls()) {
            for (auto& dish : stall.getDishes()) {
                if ((category.empty() || dish.getCategory() == category) && 
                    dish.getPrice() >= minPrice && dish.getPrice() <= maxPrice) {
                    filteredDishes.push_back(dish);
                }
            }
        }
    }

    // 如果没有符合条件的菜品，抛出异常
    if (filteredDishes.empty()) {
        throw std::runtime_error("No dishes available in the specified range and category.");
    }

    // 随机选择一个菜品
    int randomIndex = rand() % filteredDishes.size();
    return filteredDishes[randomIndex];
}

// 使用 dbOps 成员变量来获取数据。
// 实现新增的randomStallName方法
std::string RandomSelector::randomStallName() {
    auto stalls = dbOps.fetchAllStalls(); // 使用 dbOps 成员来调用 fetchAllStalls
    if (stalls.empty()) {
        throw std::runtime_error("No stalls available.");
    }
    int randomIndex = rand() % stalls.size();
    return stalls[randomIndex][1]; // 假设第二列是stall_name
}

// 实现新增的randomDishInfo方法
std::tuple<std::string, double> RandomSelector::randomDishInfo() {
    auto dishes = dbOps.fetchAllDishes();
    if (dishes.empty()) {
        throw std::runtime_error("No dishes available.");
    }
    int randomIndex = rand() % dishes.size();
    std::string dishName = dishes[randomIndex][1];
    double price = std::stod(dishes[randomIndex][2]); // 转换价格为double类型
    return std::make_tuple(dishName, price);
}