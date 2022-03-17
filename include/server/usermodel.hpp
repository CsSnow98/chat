#ifndef USERMODEL_H
#define USERMODEL_H

#include "user.hpp"

// User表的数据操作类
class UserModel
{
public:
    // 增加
    bool insert(User &user);
    // 查询
    User query(int id);
    // 更新
    bool updateState(User &user);
    // 重置
    void resetState();

private:
};

#endif