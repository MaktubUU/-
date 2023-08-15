#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
static once_flag once;
static Log *log = nullptr;
//
/*
�������ģʽ��һ�ֳ��������ģʽ������ȷ��ĳ����ֻ�ܴ���һ��ʵ����
���ڵ���ʵ����ȫ��Ψһ�ģ�����ڶ��̻߳�����ʹ�õ���ģʽʱ����Ҫ�����̰߳�ȫ�����⡣
������һ���򵥵ĵ���ģʽ��ʵ�֣�

call_once(once,func)���Ա�֤func���ܶ����̷߳��� ִֻ��һ��
����ֻ�����߳�����ʹ�á���main��ʹ�ûᱨ��
*/
class Log
{
public:
    Log() {};
    Log(const Log& log) = delete;
    Log& operator=(const Log& log) = delete;

    static Log& GetInstance()
    {
        //static Log log;//����ģʽ��

        //static Log* log = nullptr;
        //if (!log)
        //{
        //    log = new Log;
        //} ����ģʽ

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
Ϊʲôʹ�õ���ģʽ 
*/
void print_error()
{
    Log::GetInstance().printlog("in thread");
}
int main06()
{

    Log::GetInstance().printlog("error");//����ģʽ

    thread t1(print_error);
    thread t2(print_error);
    t1.join();
    t2.join();
    //ͬʱ���õĻ���new log �ᱻִ������


    return 0;
}