

// Write your code here

#include <bits/stdc++.h>
using namespace std;

/*
 * problem: https://codeforces.com/contest/1363/problem/B
 * explination: https://www.youtube.com/watch?v=5IGCnn1cqcw
 * */

int main()
{
#ifndef ONLINE_JUDGE
    //for getting input form intput.txt
    freopen("input_subsequence_hate_ip.txt", "r", stdin);
    //for writing output to output1.txt
    freopen("input_subsequence_hate_op.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int left0 = 0, left1 = 0, right0 = 0, right1 = 0,  total1 = 0, total0=0, ans=INT_MAX;

        for(char a: s)
        {
            total1+= (a == '1');
        }
        total0 = n - total1;

        for(char a: s)
        {
            if(a == '1')
            {
                left1+=1;
            } else
            {
                left0+=1;
            }
            right1 = total1 - left1;
            right0 = total0 - left0;

            ans = min(ans, min(right1 + left0, left1+right0));
        }
        cout << ans << endl;
    }
    return 0;
}