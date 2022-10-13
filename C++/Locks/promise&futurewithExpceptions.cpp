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

    promise<double> promise;

    auto do_calc = [&](int terms)
    {
        try {
        double result = calculatePi(terms);
        promise.set_value(result);   
        
        } catch (const std::exception &e) {
            promise.set_exception(current_exception());
        }
    };

    thread t1(do_calc, 0);

    future<double> future = promise.get_future();

    try {
        cout << setprecision(15) << future.get() << endl;
    } catch (const std::exception &e) {
            cout << e.what() << endl;
    }

    t1.join();

    return 0;
}