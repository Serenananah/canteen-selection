#ifndef RANDOMSELECTOR_H
#define RANDOMSELECTOR_H

#include <vector>
#include <string>
#include <tuple> // 包含tuple头文件，用于返回多个值
#include "../include/Dish.h"
#include "../include/Canteen.h"
#include "../include/DBOperation.h" // 添加对DBOperations的引用


class RandomSelector {
public:
    // 构造函数，初始化随机数种子并接收dbOps引用
    RandomSelector(DBOperations& pdbOps);
    Dish spin(double minPrice, double maxPrice, const std::string& category = "");
    // 新增方法声明
    std::string randomStallName(); // 随机选择摊位名称
    std::tuple<std::string, double> randomDishInfo(); // 随机选择菜品信息（名称和价格）

private:
    std::vector<Canteen>& canteens; // 修改为引用，以避免复制
    DBOperations& dbOps; // 数据库操作引用
};

#endif // RANDOMSELECTOR_H
