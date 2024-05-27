#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>

// 定义菜品类
class Dish {
public:
    std::string name;
    std::string category;
    double price;

    Dish(const std::string& dishName, const std::string& dishCategory, double dishPrice) : name(dishName), category(dishCategory), price(dishPrice) {}
};

// 定义菜单类
class Menu {
private:
    std::vector<Dish> dishes;

public:
    void addDish(const std::string& dishName, const std::string& dishCategory, double dishPrice) {
        dishes.push_back(Dish(dishName, dishCategory, dishPrice));
    }

    const Dish& getRandomDish(double minPrice, double maxPrice, const std::string& category) {
        std::vector<const Dish*> validDishes;
        for (const auto& dish : dishes) {
            if (dish.price >= minPrice && dish.price <= maxPrice && dish.category == category) {
                validDishes.push_back(&dish);
            }
        }

        if (validDishes.empty()) {
            throw std::runtime_error("No dish available in the specified range and category.");
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, validDishes.size() - 1);
        int randomIndex = dist(gen);

        return *validDishes[randomIndex];
    }
};

// 定义菜单处理类
class MenuHandler {
private:
    Menu menu;
    std::string menuFilename;

public:
    MenuHandler(const std::string& filename) : menuFilename(filename) {
        // 从文件中读取菜单信息
        std::ifstream file(menuFilename);
        std::string dishName, dishCategory;
        double dishPrice;

        while (file >> dishName >> dishCategory >> dishPrice) {
            menu.addDish(dishName, dishCategory, dishPrice);
        }
        file.close();
    }

    const Dish& getRandomDish(double minPrice, double maxPrice, const std::string& category) {
        return menu.getRandomDish(minPrice, maxPrice, category);
    }
};

int main() {
    // 创建菜单处理对象，从文件中读取菜单信息
    MenuHandler menuHandler("menu.txt");

    // 获取随机菜品
    try {
        const Dish& randomDish = menuHandler.getRandomDish(10.0, 20.0, "Chinese");
        std::cout << "Random Dish: " << randomDish.name << " - " << randomDish.price << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}