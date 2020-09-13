//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int cmn_sub(int i, int j, int k, string &st1, string &st2, string st3, string &result)
{

    if(st1[i] == st2[j] == st3[j])
        return 1;
}


int main() {
#ifndef ONLINE_JUDGE
    //for getting input form intput.txt
    freopen("common_substring_in3strings_ip.txt", "r", stdin);
    //for writing output to output1.txt
    freopen("common_substring_in3strings_op.txt", "w", stdout);
#endif

    string st1, st2, st3;
    cin >> st1 >> st2 >> st3;
    string result;
   int count = cmn_sub(0, 0, 0, st1, st2, st3,result);
    return 0;

}