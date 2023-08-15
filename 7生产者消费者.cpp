#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>
#include<queue>
using namespace std;
/*
condition_variable

    创建一个 std::condition_variable 对象。
    创建一个互斥锁 std::mutex 对象，用来保护共享资源的访问。
    在需要等待条件变量的地方 使用 std::unique_lock<std::mutex> 对象锁定互斥锁

    资源占用
    并调用 std::condition_variable::wait()、
    std::condition_variable::wait_for() 或 
    std::condition_variable::wait_until() 函数等待条件变量。

    资源解锁：
    在其他线程中需要通知等待的线程时，
    调用 std::condition_variable::notify_one() 或 
    std::condition_variable::notify_all() 函数通知等待的线程。
*/

queue<int>q;
condition_variable cv;
mutex mtx;
//要保证仓库在同一时间段只能进或出，给仓库加锁，

void producer()
{
    //不断的生产
    for (int i = 0; i < 100; i++)
    {
        unique_lock<mutex>lo(mtx);
        q.push(i);
        cv.notify_one();//创造完毕叫人来取
        cout << "task:" << i << endl;
        //lo.unlock();自动放锁
        this_thread::sleep_for(chrono::milliseconds(100));
    }

}
void consumer()
{
    //保持消费
    while (true)
    {
        unique_lock<mutex>lo(mtx);
        bool isempty = q.empty();
        cv.wait(lo, []() {return !q.empty();});//队列空的时候等锁，
        int value = q.front();
        q.pop();
        cout << "value:" << value << endl;
    }

}
int main()
{
    /*cout << "dsad " << endl;*/
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();

	return 0;
}