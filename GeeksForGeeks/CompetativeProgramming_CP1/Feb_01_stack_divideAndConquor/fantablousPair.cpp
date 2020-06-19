
#include <bits/stdc++.h>
using namespace std;

/*
 * An array of length at least having 2 distinct integers is said to be
 * fanatblous iff the second highest element lies strictly to the l eft of the
 * highest value. For example [1, 2, 13, 10, 15] is fantabulous as the second
 * highest value 13 lies to the left of the highest value 15. For every fantabulous
 * array, we define a fantabulous pair (a,b) where a denotes the index of the second
 * highest value(1-indexed) and b denotes the index of the highest value(1-indexed)
 * In the avove array, the fantabulous pair Macunian challenges you to solve the following
 * problem. Given an array, find the total number of fantabulous pairs over all its subarrays.
 *
 * 1 <= N <= 106
 * 1 <=  array elements <= 109
 * Array elements are distinct.
 * */

/*
 * Bit of confusion and not clear, so have taken the working solution
 * from the website:
 * https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/mancunian-and-fantabulous-pairs/editorial/
 * */

//int countFantablous(vector<long> &arr, vector<pair<int,int>> &res)
//{
//    stack<int> st;
//    int count = 0;
//
//    for(int i=0; i<arr.size(); i++)
//    {
//        while(!st.empty() && st.top() < arr[i])
//        {
//            count++;
//            res.push_back({st.top(), arr[i]});
//            st.pop();
//        }
//        st.push(arr[i]);
//    }
//    return count;
//}
//
//int main() {
//#ifndef ONLINE_JUDGE
//    //for getting input form intput.txt
//    freopen("fantablousPair_ip.txt", "r", stdin);
//    //for writing output to output1.txt
//    freopen("fantablousPair_op.txt", "w", stdout);
//#endif
//
//    int n, temp;
//    vector<long> arr;
//    vector<pair<int,int>> res;
//
//    cin >> n;
//    while(n--)
//    {
//        cin >> temp;
//        arr.push_back(temp);
//    }
//    int ans = countFantablous(arr, res);
//
//    cout<< "ans = " << ans << endl;
//    for(auto p: res)
//    {
//        cout << "(" << p.first << "," << p.second << ")" << endl;
//    }
//    return 0;
//
//}

#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
ll pwr(ll base, ll p, ll mod = MOD){
    ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}
const int N = 1000*1000+5;
int n, arr[N], next_right[N], maxlen[N], next_left[N];
set<int> distinct_;
int main(){
#ifndef ONLINE_JUDGE
    //for getting input form intput.txt
    freopen("fantablousPair_ip.txt", "r", stdin);
    //for writing output to output1.txt
    freopen("fantablousPair_op.txt", "w", stdout);
#endif
    cin>>n;
    assert(n >= 1 && n <= 1000*1000);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        assert(arr[i] >= 1 && arr[i] <= 1000*1000*1000);
        distinct_.insert(arr[i]);
    }
    assert((int)distinct_.size() == n);
    stack<int> st;
    for(int i=n;i>=1;i--){
        next_right[i] = -1;
        while(!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        if(!st.empty())
            next_right[i] = st.top();
        st.push(i);
    }
    while(!st.empty())
        st.pop();
    for(int i=1;i<=n;i++){
        next_left[i] = 0;
        while(!st.empty() && arr[st.top()] < arr[i])
            st.pop();
        if(!st.empty())
            next_left[i] = st.top();
        st.push(i);
    }
    for(int i=1;i<=n;i++){
        if(next_right[i] != -1)
            maxlen[next_right[i]-i] = max(maxlen[next_right[i]-i], i - next_left[i]);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++)
        ans += maxlen[i];
    cout<<ans;
    return 0;
}