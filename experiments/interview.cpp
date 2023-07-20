#include<iostream>
#include <string>
#include<vector>
// #include<bits/s/tdc++.h>

using namespace std;

int main()
{
    string s("This is a big string");
    
    vector<const char*> *vec = new vector<const char*>();

    for(int i = 0; i < 10; i++)
    {
        vec->push_back(s.c_str());
    }
    cout << vec->size() << endl;
    int len = vec->end() - vec->begin();
    cout << "len = " << len << endl;
}