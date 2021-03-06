#ifndef OFFLINEMESSAGEMODEL_H
#define OFFLINEMESSAGEMODEL_H

#include <string>
#include <vector>
using namespace std;

// 离线消息表的操作接口方法
class OfflineMsgModel
{
public:
    // 存储
    void insert(int userid, string msg);
    // 删除
    void remove(int userid);
    // 查询
    vector<string> query(int userid);

private:
};

#endif