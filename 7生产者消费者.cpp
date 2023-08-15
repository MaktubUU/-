#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>
#include<queue>
using namespace std;
/*
condition_variable

    ����һ�� std::condition_variable ����
    ����һ�������� std::mutex ������������������Դ�ķ��ʡ�
    ����Ҫ�ȴ����������ĵط� ʹ�� std::unique_lock<std::mutex> ��������������

    ��Դռ��
    ������ std::condition_variable::wait()��
    std::condition_variable::wait_for() �� 
    std::condition_variable::wait_until() �����ȴ�����������

    ��Դ������
    �������߳�����Ҫ֪ͨ�ȴ����߳�ʱ��
    ���� std::condition_variable::notify_one() �� 
    std::condition_variable::notify_all() ����֪ͨ�ȴ����̡߳�
*/

queue<int>q;
condition_variable cv;
mutex mtx;
//Ҫ��֤�ֿ���ͬһʱ���ֻ�ܽ���������ֿ������

void producer()
{
    //���ϵ�����
    for (int i = 0; i < 100; i++)
    {
        unique_lock<mutex>lo(mtx);
        q.push(i);
        cv.notify_one();//������Ͻ�����ȡ
        cout << "task:" << i << endl;
        //lo.unlock();�Զ�����
        this_thread::sleep_for(chrono::milliseconds(100));
    }

}
void consumer()
{
    //��������
    while (true)
    {
        unique_lock<mutex>lo(mtx);
        bool isempty = q.empty();
        cv.wait(lo, []() {return !q.empty();});//���пյ�ʱ�������
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