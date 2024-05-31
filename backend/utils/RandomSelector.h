#ifndef RANDOMSELECTOR_H
#define RANDOMSELECTOR_H

#include <vector>
#include <string>
#include "../include/Dish.h"
#include "../include/Canteen.h"

class RandomSelector {
public:
    RandomSelector(std::vector<Canteen>& canteens);
    Dish spin(double minPrice, double maxPrice, const std::string& category = "");

private:
    std::vector<Canteen>& canteens;
};

#endif // RANDOMSELECTOR_H
