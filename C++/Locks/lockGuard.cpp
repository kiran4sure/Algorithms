#include<iostream>
#include<thread>
#include<mutex>

using namespace std;


/*
    lock_guard is a mechanism for locks, if the lock goes out of scope,
    it releases the lock, these are useful or eliminates the vlunerablites when
    a lock is aquired and an exception is occured before release of the lock, then
    it will be held forever.
    in our case, the lock that is mutex will be released when it encounters the closing 
    bracket ], because this is the scope where the guard is delcared.
*/
void work(int &count, mutex &mtx)
{
    for(int i=0; i<1E6; i++)
    {
        lock_guard<mutex> guard(mtx);
        count++;
    }
    
}

int main()
{
    int count = 0;
    mutex mtx;
    
    thread t1(work, ref(count), ref(mtx));
    thread t2(work, ref(count), ref(mtx));
        
    // thread t2(func);
        
        t1.join();
        t2.join();
        
    cout << "count =" << count << endl;
}
