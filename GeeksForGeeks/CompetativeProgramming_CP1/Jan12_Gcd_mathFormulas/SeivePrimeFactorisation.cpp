#include<bits/stdc++.h>

using namespace std;

/*given a nubmer print its prime factorization
 * */

int seive[1000001];

void buildSeive()
{
    //Mark elements with number itself
    for(int i=1; i<=1e6; i++)
    {
        seive[i]=i;
    }

    for(int i=2; i*i<=1e6; i++)
    {
        if(seive[i] == i)
        {
            for(int j=i*i; j<=1e6; j+=i)
            {
                if(seive[j]==j) seive[j] = i;
            }
        }
    }
}

int main()
{
    buildSeive();
    int quaries;
    cout << "Enter number of Quaries" << endl;
    cin >> quaries;
    while(quaries--)
    {
        int num;
        cin >> num;
        int ans = 1;

        /*seive contains least prime factor for number and if number 
         * is prime then it contains the number itself
         * to calulate number of factors, we have to tranvere till
         * num != 1
         * 
         * eg:420
         * seive[420] = 2
         * num = num/2 = 210
         * seive[210] = 2
         * num = num/2 = 105
         * cnt = 2+ 1 = 3
         * 
         * seive[105] = 3
         * num = num/3 = 35
         * cnt = 1+1 = 2
         *
         * seive[35] = 5
         * num = num/5 = 7
         * cnt = 1+1 = 2
         *
         * seive[7] = 7
         * num = num/7 = 1
         * cnt = 1+1 = 2
         *
         * ans = 3x2x2x2 = 24
         * this gives the answer in log(n) time
         * and it is a better approach 
         *
         * */
        while(num!=1)
        {
            int lf = seive[num];
            int cnt = 0;
            while(seive[num] == lf)
            {
                cnt++;
                num = num/seive[num];
            }
            ans = ans *(cnt+1);
        }

        cout << ans << endl;
    }

    return 0;
}
