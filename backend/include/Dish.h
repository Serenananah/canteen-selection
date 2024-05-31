#ifndef DISH_H
#define DISH_H

#include <string>

class Dish {
public:
    Dish(const std::string& name, const std::string& category, double price);
    const std::string& getName() const;
    const std::string& getCategory() const;
    double getPrice() const;
    
private:
    std::string name;
    double price;
    std::string category;
};

#endif 