#ifndef RANDOMSELECTOR_H
#define RANDOMSELECTOR_H

#include <vector>
#include "Dish.h"

class RandomSelector {
public:
    static Dish selectRandomDish(const std::vector<Dish> &dishes, double minPrice, double maxPrice, const std::string &cuisine);
};

#endif // RANDOMSELECTOR_H