#include "chatserver.hpp"
#include <iostream>

using namespace std;

int main()
{
    EventLoop loop;
    InetAddress addr("10.112.43.148", 6000);
    ChatServer server(&loop, addr, "ChatServer");

    server.start();
    loop.loop();

    return 0;
}