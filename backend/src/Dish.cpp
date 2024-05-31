#include "../include/Dish.h"

Dish::Dish(const std::string& name, const std::string& category, double price) 
    : name(name), category(category), price(price) {}

const std::string& Dish::getName() const {
    return name;
}

const std::string& Dish::getCategory() const {
    return category;
}

double Dish::getPrice() const {
    return price;
}