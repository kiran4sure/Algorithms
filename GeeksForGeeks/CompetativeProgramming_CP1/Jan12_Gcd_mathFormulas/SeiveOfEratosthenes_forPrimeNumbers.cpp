#include<bits/stdc++.h>

using namespace std;
/*
 * create a boolean array of n and initalize all the entries
 * to true, a value in array remains true if it is prime
 * */
bool seive[1000000];

void buildSeive()
{
    memset(seive, true, sizeof(seive));
    seive[0] = seive[1] = false;
    for(int i=2; i*i<=1e6; i++)
    {
        //if seive[i] is true then it is a prime
        if(seive[i] == true)
        {
            /*update all multiples of i greater than or equal to
             * square of it. numbers wich are multiple of i and 
             * are less than i^2 are already been marked.
             * */
            for(int j = i*i; j<=1e6; j+=i)
            {
                if(seive[j] == true) seive[j] = false;
            }
        }
    }
}

int main()
{
    int quaries;
    cout << "Enter number of quaries" << endl;
    buildSeive();
    cin >> quaries;
    while(quaries--)
    {
        int num;
        cin >> num;
        cout << (int)seive[num] << endl;
    }
}
