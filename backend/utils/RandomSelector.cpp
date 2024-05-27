#include "RandomSelector.h"
#include <cstdlib>
#include <ctime>

Dish RandomSelector::selectRandomDish(const std::vector<Dish> &dishes, double minPrice, double maxPrice, const std::string &cuisine) {
    std::vector<Dish> filteredDishes;
    for (const auto &dish : dishes) {
        if (dish.getPrice() >= minPrice && dish.getPrice() <= maxPrice && dish.getCuisine() == cuisine) {
            filteredDishes.push_back(dish);
        }
    }

    if (filteredDishes.empty()) {
        throw std::runtime_error("No dish found in the specified range and cuisine.");
    }

    std::srand(std::time(nullptr));
    int index = std::rand() % filteredDishes.size();
    return filteredDishes[index];
}