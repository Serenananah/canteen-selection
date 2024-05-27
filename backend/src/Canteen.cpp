#include "Canteen.h"

Canteen::Canteen(const std::string &name) : name(name) {}

void Canteen::addStall(const Stall &stall) {
    stalls.push_back(stall);
}

const std::vector<Stall>& Canteen::getStalls() const {
    return stalls;
}

std::string Canteen::getName() const {
    return name;
}