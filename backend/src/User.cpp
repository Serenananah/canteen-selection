#include "User.h"
#include <iostream>

User::User(int id, std::string uname, std::string pwd) : user_id(id), username(uname), password(pwd) {}

Customer::Customer(int id, std::string uname, std::string pwd) : User(id, uname, pwd) {}

void Customer::display() {
    std::cout << "Customer ID: " << user_id << " Username: " << username << std::endl;
}

Admin::Admin(int id, std::string uname, std::string pwd) : User(id, uname, pwd) {}

void Admin::display() {
    std::cout << "Admin ID: " << user_id << " Username: " << username << std::endl;
}