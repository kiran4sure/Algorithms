#include<iostream>
#include<thread>
#include<mutex>

using namespace std;

int main()
{
    int count = 0;
    const int ITERATIONS = 1000;
    
    mutex mtx1;
    
    auto func = [&](){
        for(int i=0; i<ITERATIONS; i++)
            mtx1.lock();
            count++;
            mtx1.unlock();
        };
    
    thread t1(func);
        
    thread t2(func);
        
        t1.join();
        t2.join();
        
    cout << "count =" << count << endl;
}
