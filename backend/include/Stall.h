//档口
#ifndef STALL_H
#define STALL_H

#include <vector>
#include <string>
#include "Dish.h"

class Stall {
public:
    Stall(const std::string &name);
    void addDish(const Dish &dish);
    const std::vector<Dish>& getDishes() const;
    std::string getName() const;
    
private:
    std::string name;
    std::vector<Dish> dishes;
};

#endif // STALL_H