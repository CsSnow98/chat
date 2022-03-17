#ifndef GROUPMODEL
#define GROUPMODEL

#include "group.hpp"

class GroupModel
{
public:
    //创建群组
    bool createGroup(Group &group);
    // 加入群组
    void addGroup(int userid, int groupid, string role);
    // 查询群组
    vector<Group> queryGroups(int userid);
    // 查询群组成员
    vector<int> queryGroupUsers(int userid, int groupid);

private:

};


#endif