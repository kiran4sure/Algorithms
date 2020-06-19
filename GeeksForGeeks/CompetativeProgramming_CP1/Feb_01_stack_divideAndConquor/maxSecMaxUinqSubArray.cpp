
#include <bits/stdc++.h>
using namespace std;
/*
 * Given a permutation of number from 1 to N. Among all the sub-arrays, find
 * the number of unique paris (a,b) such that a!=b and a is maximum and b is
 * second maximum in that subarray.
 *
 * eg : {4,3,1,5,2}
 *
 * sub arrays are:
 * 4
 * 4 3                  -->(4,3)
 * 4 3 1                -->(4,3)
 * 4 3 1 5              -->(5,4)
 * 4 3 1 5 2
 *
 *3
 *3 1                   -->(3,1)
 *3 1 5                 -->(5,3)
 *3 1 5 2
 *
 * 1
 * 1 5                  -->(5,1)
 * 1 5 2
 *
 * 5
 * 5 2                  -->(5,2)
 *
 * so answer is 6 pairs, since we want uique paris, we neglect duplicate pairs
 * answer = 6
 * */

#define Vl vector<long>
#define rep(a,b) for(long i=a; i<b; i++)


int countSubArry(Vl &arr, vector<pair<int, int>> &res)
{
    stack<long> st;
    int count = 0;

    for(int i = 0; i < arr.size(); i++) {
        while (!st.empty() && st.top() <= arr[i])
        {
            count++;
            res.push_back({arr[i], st.top()});
            st.pop();
        }

        if(!st.empty())
        {
            res.push_back({st.top(), arr[i]});
            count++;
        }
        st.push(arr[i]);
    }
    return count;
}

int main() {
#ifndef ONLINE_JUDGE
    //for getting input form intput.txt
    freopen("maxSecMaxUinqSubArray_ip.txt", "r", stdin);
    //for writing output to output1.txt
    freopen("maxSecMaxUinqSubArray_op.txt", "w", stdout);
#endif

    int n, temp;
    Vl arr;
    vector<pair<int,int>> res;

    cin >> n;
    rep(0,n)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    int ans = countSubArry(arr, res);

    cout << "ans = " << ans << endl;

    for(auto p: res)
    {
        cout << "(" << p.first << "," << p.second << ")" << endl;
    }
    return 0;
}