#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int low, int high)
{
    int mid = (low+high)/2;
    vector<int> temp(arr.begin(), arr.end());//.begin()+low, arr.begin()+high);
    int first = low;
    int second = mid+1;
    int count = high - low;

    for(int i=0; i< count; i++)
    {
        if(temp[first] <= temp[second])
        {
            arr[low+i] = temp[first];
            first++;
        }
        else
        {
            arr[low+i] = temp[second];
            second++;
        }
        
    }
}

void merge_sort(vector<int> &arr, int low, int high)
{

    if(low < high)
    {
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, high);
    }

}

void exp(vector<int> &arr, int low, int high)
{
    vector<int> temp(arr.begin()+low, arr.begin()+high);

    cout << "array size = " << temp.size() << endl;
    for(auto a: temp)
    {
        cout << a << " ";
    }   
    cout << endl;
}

int main()
{
    vector<int> arr{7,5,1,20,3,5,10,7,1};
    int mid, low, high;

    cout << "orginal array: " << endl;
    for(auto element: arr)
        cout << element << " ";
    cout << endl;
    low = 0;
    high = arr.size()-1;
    merge_sort(arr, low, high);

    cout << "sorted array: " << endl;
    for(auto element: arr)
        cout << element << " ";
    cout << endl;
    return 0;
}