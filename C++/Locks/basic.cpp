//#include<iostream>
//#include<thread>
//
//using namespace std;
//
//int main()
//{
//    atomic<int> count = 0;
//    const int ITERATIONS = 1e6;
//    thread t1([&](){
//        for(int i=0; i<ITERATIONS; i++)
//            count++;
//        });
//        
//    thread t2([&](){
//        for(int i=0; i<ITERATIONS; i++)
//            count++;
//        });
//        
//        t1.join();
//        t2.join();
//        
//    cout << "count =" << count << endl;
//}
