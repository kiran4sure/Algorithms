#include <iostream>

using namespace std;
class one{

public:
    int val1[2];
    int val2;
    void print()
    {
        cout << "val1 = " << val1 << ", val2 = " << val2 << endl;
        cout << val1[0] << "," << val1[1] << endl;
        cout << "=======" << endl;
    }

    one& operator=(const one &rval)
    {
        cout << "inside operator overload" << endl;
        val1[0] = rval.val1[0];
        val1[1] = rval.val1[1];
        val2 = rval.val2;
        return *this;
    }

};

void fun()

int main() {
    one o1;
    o1.val1[0] = 1;
    o1.val1[1] = 2;
    o1.val2 = 3;
//    o1.print();

    one o2(o1);
//    o2.print();
    o2.val1[0] = 45;
//    o1.print();
//    o2.print();


//    one o4;// = new one();
    one o3;// = o4;
    o3 = o2;
    o3.print();
    return 0;
}
