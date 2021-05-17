#include<iostream>
#include<vector>
#include<map>

using namespace std;




map<int,int> fun(vector<int> &vec)
{
    map<int,int> mp;

    for(int a: vec)
    {
        if(mp.count(a))
        {
            mp[a]++;
        }
        else
        {
            mp.insert({a,1});
        }
    }

    return mp;

}


int main()
{
    vector<int> vec{0,1,2,3,3,4,5,5,5,6,7,8,8};

    map<int, int> mp = fun(vec);

    for(auto a = mp.begin(); a!=mp.end(); a++)
    {
        cout << a->first << " --> " << a->second << endl;
    }

    return 0;
}