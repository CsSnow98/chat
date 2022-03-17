#ifndef GROUPUSER_H
#define GROUPUSER_H

#include "user.hpp"
#include <string>
// 群组用户
class GroupUser : public User
{
public:
    void setRole(string role) { this->role = role; }
    string getRole() { return this->role; }
private:
    string role;
};

#endif