#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string &name);
    std::string getName() const;
    
private:
    std::string name;
};

#endif // USER_H