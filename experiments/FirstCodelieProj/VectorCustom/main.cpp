#include<bits/stdc++.h>

using namespace std;


template<typename Vector>
class VectorItrator {

public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType*;
    using RefrenceType = ValueType&;
    
    
    
};




template<typename T>
class Vector{

    T *arr;
    int _size;
    int _capacity;
    
    void validate()
    {
        if(_size == _capacity)
        {
            _capacity *= 2;
            T* temp = new T(_capacity);
            for(int i=0; i<_size; i++)
            {
                temp[i] = arr[i];
            }
                delete arr;
                arr = temp;
        }
    }
    
public:
    using ValueType = T;
    Vector()
    :_capacity(2), _size(0)
    {
        arr = new T(_capacity);
    }
    
    void push_back(const T& element)
    {
        validate();
        arr[_size++] = element;
    }
    
    int size() const{
        return _size;
    }
    
    int capacity() const{
        return _capacity;
    }
    
    T pop()
    {
        _size--;
        return arr[_size];
    }
    
    T& operator[](int num) const{
        return arr[num];
    }
    
    
  
};


int main()
{
    cout << "in main" << endl;
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    
    for(int i=0; i<vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
    cout << vec.size() << endl;
    return 0;
}