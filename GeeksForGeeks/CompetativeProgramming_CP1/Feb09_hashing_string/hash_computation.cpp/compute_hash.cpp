#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

#define mod (int)1e7+5

using namespace std;

int comp_hash(string &str)
{
    int hash = 0;
    int n = str.size();
    int pr = 1;

    for(int i=0; i<n; i++)
    {
        hash = (hash+((str[i]-'a'+1)*pr)%mod)%mod;

        pr = pr*31; //we are using 31 as prime
    }

    return hash;

}

int main() {
// #ifndef ONLINE_JUDGE
//     //for getting input form intput.txt
//     freopen("compute_hash_ip.txt", "r", stdin);
//     //for writing output to output1.txt
//     freopen("compute_hash_op.txt", "w", stdout);
// #endif

    string str;
    int n;
    cout << "Enter number of strings" << endl;
    cin >> n;
    while(n--)
    {
        cout << "Enter remaning " << n+1 << " strings" << endl;
        cin >> str;
        int result = comp_hash(str);
       cout << "hash of " << str << " = " << result << endl;
    }
    return 0;

}