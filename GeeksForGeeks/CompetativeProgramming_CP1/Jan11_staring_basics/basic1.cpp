#include<bits/stdc++.h>
using namespace std;


int main()
{
    double x = 3.1456;

    /*This sets the precesion to 2 digit places not decimal places, it rounds of and sets.
     in the below it will be 3.1 becuse it roudns off*/
    cout << setprecision(2) << x << endl;
    
    /*This will be 3.15*/
    cout << setprecision(3) << x << endl;

    /**********STRING OPERATIONS***********/
    string s = "gfg";

    int n = s.size();
    int m = s.length();
    /*both will print 3, size and length are literally same in C++*/
    cout << m << " " << n << endl;

    cout << s << endl; //gfg

    s.pop_back(); // this is remove one element from the back
    cout << s << endl; //gfg
    s.push_back('g'); // this will append a char to back
    cout << s << endl; //gfg


    /***********BINARY SEARCH***********/
    int len;
    cout << "Enter array size" << endl;
    cin >> len;
    int arr[len];
    cout << "Enter " << len << " elements" << endl;

    for(int i=0; i<len; i++)
        cin >> arr[i];
    
    cout << "Elemet to search" << endl;
    int element;
    cin >> element;

    int low = 0;
    int high = len-1;
    int index = -1;

    while(low <= high)
    {
        int mid = (low + high)/2;

        if(element == arr[mid])
        {
            index = mid;
            break;
        }
        else if(element < arr[mid])
        {
            high = mid -1;
        }
        else
        {
            low = high +1;
        }
    }

    (index==-1)?cout << element << " not found" << endl:cout << "element is present at " << index << endl; 
    return 0;
}