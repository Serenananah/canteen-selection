#include "Dish.h"

Dish::Dish(const std::string &name, double price, const std::string &cuisine) 
    : name(name), price(price), cuisine(cuisine) {}

std::string Dish::getName() const {
    return name;
}

double Dish::getPrice() const {
    return price;
}

std::string Dish::getCuisine() const {
    return cuisine;
}