#include<bits/stdc++.h>
using namespace std;

/*PROBLEM
given an array of N elements, find mimium value of K on whose 
division  the sum of array does not exceeds S, where S is given

eg:
S = 10; 
arr = 2 4 10 5 // sum of array = 21 which is greater than S=10, divide the array by 1 to ..
arr = 1 2 5 2 // sum = 10, which is not greater than 10, so ans is 2
*/

int main()
{

    int n;
    int ans = 0;

    cout << "Enter arry size" << endl; 
    cin >> n;
    int arr[n];
    int S;
    cout << "Enter S vlaue" << endl;
    cin >> S;
    int maxi = INT_MIN; // to hold the max in array

    cout << "Enter " << n << " elements for the array" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
        maxi = max(maxi, arr[i]); 
    }

    int low = 0, high = maxi+1; // maxi should be one greater because if ans is lesser than have to covert all elemnets 0   
    ans = high;

    while(low <= high)
    {
        int mid = (low+high)/2;
        int sum = 0;

        for(int a: arr)
            sum += a/mid;
        
        if(sum > S)
        {
            low = mid+1;
        }
        else
        {
            ans = min(ans, mid);
            high = mid-1;
        }        
    }

    cout << "answer = " << ans << endl;
    return 0;
}