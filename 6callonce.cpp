#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
static once_flag once;
static Log *log = nullptr;
//
/*
单例设计模式是一种常见的设计模式，用于确保某个类只能创建一个实例。
由于单例实例是全局唯一的，因此在多线程环境中使用单例模式时，需要考虑线程安全的问题。
下面是一个简单的单例模式的实现：

call_once(once,func)可以保证func不管多少线程访问 只执行一次
并且只能在线程里面使用、在main中使用会报错
*/
class Log
{
public:
    Log() {};
    Log(const Log& log) = delete;
    Log& operator=(const Log& log) = delete;

    static Log& GetInstance()
    {
        //static Log log;//懒汉模式，

        //static Log* log = nullptr;
        //if (!log)
        //{
        //    log = new Log;
        //} 饿汉模式

        if (!log) log = new Log;
        call_once(once, init);
        return *log;
    }
    static void init()
    {
        if (!log)
        {
            log = new Log;
        }
    }
    void printlog(string msg)
    {
        cout <<__TIME__<<" " << msg << endl;
    }
};


//class Singleton {
//public:
//    static Singleton& getInstance() {
//        static Singleton instance;
//        return instance;
//    }
//    void setData(int data) {
//        m_data = data;
//    }
//    int getData() const {
//        return m_data;
//    }private:
//        Singleton() {}
//        Singleton(const Singleton&) = delete;
//        Singleton& operator=(const Singleton&) = delete;
//        int m_data = 0;
//};

/*
为什么使用单例模式 
*/
void print_error()
{
    Log::GetInstance().printlog("in thread");
}
int main06()
{

    Log::GetInstance().printlog("error");//单例模式

    thread t1(print_error);
    thread t2(print_error);
    t1.join();
    t2.join();
    //同时调用的话，new log 会被执行两次


    return 0;
}