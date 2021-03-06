#ifndef CHATSERVICE_H
#define CHATSERVICE_H

#include "muduo/net/TcpConnection.h"
// #include <functional>
#include "json.hpp"
#include <unordered_map>
#include "usermodel.hpp"
#include <mutex>
#include "offlinemessagemodel.hpp"
#include "friendmodel.hpp"
#include "groupmodel.hpp"
#include "redis.hpp"

using namespace muduo;
using namespace muduo::net;
using namespace std;
using json = nlohmann::json;

// 处理消息的时间回调方法类型
using MsgHandler = std::function<void(const TcpConnectionPtr &conn, json &js, Timestamp)>;

// 聊天服务器业务类
class ChatService
{
public:
    // 获取单例对象的接口函数
    static ChatService *instance();
    // 登陆业务
    void login(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 注册业务
    void reg(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 客户端异常退出
    void clientCloseException(const TcpConnectionPtr &conn);
    // 一对一聊天业务
    void oneChat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 添加好友
    void addFriend(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 创建群组
    void createGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 加入群组
    void addGroup(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 群组聊天
    void groupChat(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 客户端登出
    void loginout(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 压力测试
    void test(const TcpConnectionPtr &conn, json &js, Timestamp time);
    // 服务器异常重置
    void reset();
    // 获取事件分发器
    MsgHandler getHandler(int msgid);

    void handleRedisSubscribeMessage(int, string);

private:
    ChatService();
    // 存储消息id和对应的业务处理办法
    unordered_map<int, MsgHandler> _msgHandlerMap;
    // 存储在线用户的通信连接
    unordered_map<int, TcpConnectionPtr> _userConnMap;
    // 定义互斥锁
    mutex _connMutex;
    // 数据操作类对象
    UserModel _userModel;
    OfflineMsgModel _offlineMsgModel;
    FriendModel _friendModel;
    GroupModel _groupModel;

    Redis _redis;
};

#endif