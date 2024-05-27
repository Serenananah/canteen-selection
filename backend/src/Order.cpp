#include "Order.h"

Order::Order(const std::string &userName) : userName(userName) {}

void Order::addDish(const Dish &dish) {
    dishes.push_back(dish);
}

std::string Order::getUserName() const {
    return userName;
}

const std::vector<Dish>& Order::getDishes() const {
    return dishes;
}