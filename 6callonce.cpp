#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
//
/*
单例设计模式是一种常见的设计模式，用于确保某个类只能创建一个实例。
由于单例实例是全局唯一的，因此在多线程环境中使用单例模式时，需要考虑线程安全的问题。
下面是一个简单的单例模式的实现：
*/
class Log
{
public:
    Log() {};
    Log(const Log& log) = delete;
    Log& operator=(const Log& log) = delete;

    static Log& GetInstance()
    {
        static Log log;//懒汉模式，

        //static Log* log = nullptr;
        //if (!log)
        //{
        //    log = new Log;
        //} 饿汉模式

        return log;
    }
    void printlog(string msg)
    {
        cout << msg << endl;
    }
};


class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
    void setData(int data) {
        m_data = data;
    }
    int getData() const {
        return m_data;
    }private:
        Singleton() {}
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        int m_data = 0;
};
int main()
{


    return 0;
}