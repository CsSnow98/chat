#include "json.hpp"
using json = nlohmann::json;

#include <iostream>
#include <vector>
#include <map>

using namespace std;

string fun1()
{
    json js;
    js["id"] = 1;
    js["name"] = "zhang san";
    // 添加对象
    js["msg"]["zhang san"] = "hello world";
    js["msg"]["liu shuo"] = "hello china";
    // 上面等同于下面这句一次性添加数组对象
    js["msg"] = {{"zhang san", "hello world"}, {"liu shuo", "hello china"}};

    string sendBuf = js.dump(); // json数据对象 -》 序列化成 json字符串
    // cout << js << endl;
    // cout << sendBuf.c_str() << endl;
    return sendBuf;
}
void fun2()
{
    json js;
    // 直接序列化一个vector容器
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    js["list"] = vec;
    // 直接序列化一个map容器
    map<int, string> m;
    m.insert({1, "黄山"});
    m.insert({2, "华山"});
    m.insert({3, "泰山"});
    js["path"] = m;
    cout << js << endl;
}
int main()
{
    string recvBuf = fun1();
    // 数据的反序列化 json字符串 -》 反序列化 数据对象 （看作容器，方便访问）
    json jsbuf = json::parse(recvBuf);
    cout << jsbuf["msg"] << endl; 
    return 0;
}