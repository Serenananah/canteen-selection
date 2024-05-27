#ifndef CANTEEN_H
#define CANTEEN_H

#include <vector>
#include <string>
#include "Stall.h"

class Canteen {
public:
    Canteen(const std::string &name);
    void addStall(const Stall &stall);
    const std::vector<Stall>& getStalls() const;
    std::string getName() const;
    
private:
    std::string name;
    std::vector<Stall> stalls;
};

#endif // CANTEEN_H