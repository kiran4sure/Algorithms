
#include<bits/stdc++.h>
using namespace std;

/* Problem
    find the higest integer whose square is less than or equal to N
    eg:
    N = 16;
    ans = 4; //4x4
    N = 20;
    ans = 4; // 3x3 will be less than 4x4, but 5x5 will be more than 20, so ans is 4
*/


//from video
int higestSquareRoot(int n)
{
    int low = 0, high = n;
    int ans = 0;

    while(low <= high)
    {
        int mid = (low+high)/2;

        if(mid*mid <= n)
        {
            ans = max(ans, mid);
            low = mid+1;
        }
        else
        {
            high = mid - 1;
        }
    }
        return ans;
}

int main()
{
    int n{22};

    cout << higestSquareRoot(n) << endl; 
}