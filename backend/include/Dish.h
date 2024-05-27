#ifndef DISH_H
#define DISH_H

#include <string>

class Dish {
public:
    Dish(const std::string &name, double price, const std::string &cuisine);
    std::string getName() const;
    double getPrice() const;
    std::string getCuisine() const;
    
private:
    std::string name;
    double price;
    std::string cuisine;
};

#endif // DISH_H