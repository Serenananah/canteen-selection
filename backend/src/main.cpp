#include <iostream>
#include "Canteen.h"
#include "User.h"
#include "Order.h"
#include "RandomSelector.h"
#include "../utils/RandomSelector.h"

int main() {
    // 创建食堂和菜品
    Canteen canteen1("Canteen 1");
    Stall stall1("Stall 1");
    stall1.addDish(Dish("Dish 1", "Chinese", 12.5));
    stall1.addDish(Dish("Dish 2", "Western", 15.0));
    stall1.addDish(Dish("Dish 3", "Chinese", 8.0));
    canteen1.addStall(stall1);

    Canteen canteen2("Canteen 2");
    Stall stall2("Stall 2");
    stall2.addDish(Dish("Dish 4", "Chinese", 10.0));
    stall2.addDish(Dish("Dish 5", "Western", 20.0));
    stall2.addDish(Dish("Dish 6", "Japanese", 25.0));
    canteen2.addStall(stall2);

    std::vector<Canteen> canteens = {canteen1, canteen2};
    RandomSelector wheel(canteens);

    try {
        Dish randomDish = wheel.spin(10.0, 20.0, "Chinese");
        std::cout << "Randomly selected dish: " << randomDish.getName() 
                  << " (" << randomDish.getCategory() << ") - " 
                  << randomDish.getPrice() << " RMB" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    DBOperations dbOps;

    // Fetch and display all canteens
    auto canteens = dbOps.fetchAllCanteens();
    for (const auto& canteen : canteens) {
        std::cout << "Canteen ID: " << canteen[0] << ", Name: " << canteen[1] << std::endl;
    }

    // Fetch and display stalls for a specific canteen
    int canteen_id = 1; // Example canteen_id
    auto stalls = dbOps.fetchStallsByCanteen(canteen_id);
    for (const auto& stall : stalls) {
        std::cout << "Stall ID: " << stall[0] << ", Name: " << stall[1] << std::endl;
    }


    return 0;
}