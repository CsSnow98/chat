#ifndef CHATSERVICE_H
#define CHATSERVICE_H

#include "muduo/net/TcpConnection.h"
// #include <functional>
#include "json.hpp"
#include <unordered_map>
#include "usermodel.hpp"
#include <mutex>

using namespace muduo;
using namespace muduo::net;
using namespace std;
using json = nlohmann::json;

using MsgHandler = std::function<void(const TcpConnectionPtr &conn, json &js, Timestamp)>;
class ChatService
{
public:
    static ChatService *instance();

    void login(const TcpConnectionPtr &conn, json &js, Timestamp time);
    void reg(const TcpConnectionPtr &conn, json &js, Timestamp time);

    MsgHandler getHandler(int msgid);

private:
    ChatService();
    unordered_map<int, MsgHandler> _msgHandlerMap;
    unordered_map<int, TcpConnectionPtr> _userConnMap;
    mutex _connMutex;
    UserModel _userModel;
};

#endif