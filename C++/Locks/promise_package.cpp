#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <thread>
#include <future>
#include<exception>

using namespace std;


double calculatePi(int terms)
{
    double sum = 0.0;

    if(terms < 1)
    {
        throw runtime_error(" terms cannot be less than 1");
    }

    for(int i=0; i<terms; i++)
    {
        int sign = pow(-1, i);
        double term = 1.0/(i*2+1);
        sum+= sign * term;
    }

    return sum *4;
}


int main()
{
    packaged_task<double(int)> task1(calculatePi);

    future<double> future1 = task1.get_future();
    thread t1(move(task1), 1E6);

    double result = future1.get();

    cout << result << endl;

    t1.join();
    
    return 0;
}