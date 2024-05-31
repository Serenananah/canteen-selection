#include "RandomSelector.h"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

// 构造函数，初始化随机数种子
RandomSelector::RandomSelector(std::vector<Canteen>& c) : canteens(c) {
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
