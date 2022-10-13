#include<iostream>
#include<thread>
#include<mutex>

using namespace std;


/*
    callable function or object is a method which overrides 
    the callable operator, callable operator is the double brackets ().
*/
class app
{
    mutex mtx;
public:
    int count = 0;
    void operator()()
    {
        for(int i=0; i<1E6; i++)
        {
            lock_guard<mutex> guard(mtx);
            count++;
        }

    }


};

int main()
{
    app ap;

    thread t1(ref(ap));
    thread t2(ref(ap));
        
    t1.join();
    t2.join();
        
    cout << "count =" << ap.count << endl;
}
