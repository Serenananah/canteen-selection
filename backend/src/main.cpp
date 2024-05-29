#include <iostream>
#include "Canteen.h"
#include "User.h"
#include "Order.h"
#include "RandomSelector.h"
#include "DBOperations.h"

int main() {
    Canteen canteen1("Canteen 1");
    Stall stall1("Stall 1");
    Dish dish1("Dish 1", 10.0, "Chinese");
    Dish dish2("Dish 2", 12.0, "Chinese");

    stall1.addDish(dish1);
    stall1.addDish(dish2);
    canteen1.addStall(stall1);

    User user("Alice");
    Order order(user.getName());

    try {
        Dish randomDish = RandomSelector::selectRandomDish(stall1.getDishes(), 5.0, 15.0, "Chinese");
        order.addDish(randomDish);
        std::cout << "Random dish selected: " << randomDish.getName() << std::endl;
    } catch (const std::runtime_error &e) {
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