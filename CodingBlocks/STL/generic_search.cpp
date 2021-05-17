// C++ program for the Comparator Class
#include <iostream>
#include <string>
#include <list>
#include <functional>
#include <vector>
using namespace std;

bool def_fun(int first, int second)
{
    return first == second;
}

template<class T>
int validate(vector<T> &vec, T ToFind, std::function<bool(T, T)> fcn = def_fun) // std::function method that returns a bool and takes two int parameters
{
    int ret = -1;

    for(int i=0; i<vec.size(); i++)
    {
        if(fcn(vec[i], ToFind))
        {
            ret = i;
            break;
        }
    }

    return ret;
}

struct student
{
    string name;
    int rollNum;

    student(const string &name, int rollNum) : name(name), rollNum(rollNum) {}
};

bool st_fltr(student first, student second)
{
    return first.name == second.name;
}

//xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

class cmp
{
public:
    bool operator()(int a, int b)
    {
        return a == b;
    }
};
cmp CMP;

class cmp_cls
{
public:
    bool operator()(student one, student two)
    {
        return one.rollNum == two.rollNum;
    }
};

template<class T, class compare>
int search(vector<T> &vec, T ToFind, compare obj=CMP)
{
    int result = -1;
    for(int i=0; i<vec.size(); i++)
    {
        if(obj(vec[i], ToFind))
        {
            result = i;
            break;
        }
    }
    return result;
}



int main()
{

    vector<int> vec{1,4,2,6,8,3,89,3,5,768,2343,65,33,22,75,34};

    int ToFind = 65;
    int result = validate(vec,ToFind);
    string output = "result ";
    output += (result == -1)?"not":"";
    output +=" found";
    cout << output << endl;
    if(result !=-1)
    {
        cout << "To Find: " << ToFind << ", loc = " << result << " val = " << vec[result] << endl;
    }

    cout <<"===============================" << endl;

    student s1("kiran", 1);
    student s2("pavan", 2);
    student s3("xiaotian", 3);
    student s4("sathya", 4);
    student s5("Yung yue", 5);
    student s6("Trung", 6);

    vector<student> st;
    st.push_back(s1);
    st.push_back(s2);
    st.push_back(s3);
    st.push_back(s4);
    st.push_back(s5);
    st.push_back(s6);

    student ToFindSt = s3;
    result = validate<student>(st, ToFindSt, st_fltr);
    output = "result ";
    output += (result == -1)?"not":"";
    output +=" found";
    cout << output << endl;
    if(result !=-1)
    {
        cout << "To Find: " << ToFindSt.name << ", loc = " << result << " val = " << st[result].name << endl;
    }
    cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;

    result = search(vec, ToFind, CMP);
    output = "result ";
    output += (result == -1)?"not":"";
    output +=" found";
    cout << output << endl;
    if(result !=-1)
    {
        cout << "To Find: " << ToFind << ", loc = " << result << " val = " << vec[result] << endl;
    }

    cout <<"===============================" << endl;
    cmp_cls CMP_CLS;
    result = search(st, ToFindSt, CMP_CLS);
    output = "result ";
    output += (result == -1)?"not":"";
    output +=" found";
    cout << output << endl;
    if(result !=-1)
    {
        cout << "To Find: " << ToFindSt.name << ", loc = " << result << " val = " << st[result].name << endl;
    }


}


