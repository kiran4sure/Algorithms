#include <bits/stdc++.h>
using namespace std;

/*
 * problem: https://codeforces.com/contest/1366/problem/C
 * explination: https://www.youtube.com/watch?v=5IGCnn1cqcw
 * */

#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    //for getting input form intput.txt
    freopen("matrix_palindromic_paths_ip.txt", "r", stdin);
    //for writing output to output1.txt
    freopen("matrix_palindromic_paths_op.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        /*
         * matrix has n+m-1 diagonals, since middle diagonal is common, its n+m-1
         * and diagonal elements count of n+m will be same eg: [01,10], [20,11,30]...
         * require 2-d matix to store count of 0 in one and count of 1 in one.
         * */
//        int  count[n + m - 1][2] = {};
        int  count[1000][2] = {}; //for some compiler error
        bool ip; //for input
        int ans = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
            {
                /*
                 * every element falls in any one diagonal and we are counting
                 * the 1's and 0's since it is binary array
                 */
                cin >> ip;
                 count[i+j][ip]++;
            }
        /*
         * we have to count only till middle since we taking into account the start
         * and end for count at the same time, so it is /2
         * */
        for(int i=0; i<(n+m-1)/2; i++)
            ans+=min(count[i][0]+count[n+m-2-i][0], count[i][1]+count[n+m-2-i][1]);

        cout << ans << endl;
    }
    return 0;
}