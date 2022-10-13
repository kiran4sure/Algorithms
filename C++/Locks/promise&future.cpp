#include <iostream>
#include <cmath>
#include <iomanip>
#include <thread>
#include <future>


using namespace std;


double calculatePi(int terms)
{
    double sum = 0.0;

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

    promise<double> promise;

    auto do_calc = [&](int terms)
    {
        double result = calculatePi(terms);
        promise.set_value(result);   
    };

    thread t1(do_calc, 1E7);

    future<double> future = promise.get_future();

    cout << setprecision(15) << future.get() << endl;

    t1.join();

    return 0;
}