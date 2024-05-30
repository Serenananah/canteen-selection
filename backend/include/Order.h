#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include "Dish.h"

class Order {
public:
    Order(const std::string &userName);
    void addDish(const Dish &dish);
    std::string getUserName() const;
    const std::vector<Dish>& getDishes() const;
    
private:
    std::string userName;
    std::vector<Dish> dishes;
};

#endif 