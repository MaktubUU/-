#include<iostream>
#include<mutex>
#include<thread>
using namespace std;
//
/*
�������ģʽ��һ�ֳ��������ģʽ������ȷ��ĳ����ֻ�ܴ���һ��ʵ����
���ڵ���ʵ����ȫ��Ψһ�ģ�����ڶ��̻߳�����ʹ�õ���ģʽʱ����Ҫ�����̰߳�ȫ�����⡣
������һ���򵥵ĵ���ģʽ��ʵ�֣�
*/
class Log
{
public:
    Log() {};
    Log(const Log& log) = delete;
    Log& operator=(const Log& log) = delete;

    static Log& GetInstance()
    {
        static Log log;//����ģʽ��

        //static Log* log = nullptr;
        //if (!log)
        //{
        //    log = new Log;
        //} ����ģʽ

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