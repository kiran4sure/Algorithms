#include <iostream>
#include <future>
#include <chrono>
#include <mutex>

using namespace std;


int work(int id, mutex &mtx)
{
    for (int i = 0; i < 5; i++)
    {
        unique_lock<mutex> lock(mtx);
        cout << "running " << id << endl;
        lock.unlock();
        this_thread::sleep_for(chrono::milliseconds(1000));
    }

    return id * 7;
}

int main()
{
    mutex mtx;
    future<int> f1 = async(launch::async, work, 0, ref(mtx));
    future<int> f2 = async(launch::async, work, 1, ref(mtx));

    cout << f1.get() << endl;
    cout << f2.get() << endl;
    return 0;
}