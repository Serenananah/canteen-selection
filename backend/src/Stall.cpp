#include "Stall.h"

Stall::Stall(const std::string &name) : name(name) {}

void Stall::addDish(const Dish &dish) {
    dishes.push_back(dish);
}

const std::vector<Dish>& Stall::getDishes() const {
    return dishes;
}

std::string Stall::getName() const {
    return name;
}