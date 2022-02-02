#include <bits/stdc++.h>
using namespace std;
/*
 * segment trees are useful in range quaries.
 * cons:
 *      size of segment tree can go upto 4*N,
 *      where N is the size of input array.
 *  node index can be calculated by the formula:
 *  2*index+1
 *  2*index-1,
 *  where index is the parent index.
 *  range of each index is calculated by:
 *  parent range(l+r)/2 and r - (l+r)/2,
 *  basically we are dividing the range into equal parts
 * eg:
 * parent range [0-9]
 * left child = 0+9/2 = 4, [0-4]
 * right child = 9- 0+9/2 = 5, [5-9]
 *
 * time complexity to build segment tree:
 * O(N)
 * since it has 2n-1 nodes
 *
 * time to query:
 * O(logN)
 * */
//array for storing segment tree
int seg[4*100005];


//void build(vector<int> &arr, int ind, int low, int high)
//{
//    if(low==high){
//        seg[ind] = arr[low];
//        return;
//    }
//    int mid = (low+high)/2;
//    build(arr, 2*ind+1, low, mid);
//    build(arr, 2*ind+2, mid+1, high);
//    //store the maximum of left and right tree
//    seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
//}

void build(vector<int> &arr, int ind, int low, int high)
{
    if(low==high)
    {
        seg[ind] = arr[low];
        return;
    }

    int mid = (low+high)/2;
    build(arr, 2*ind+1, low, mid);
    build(arr, 2*ind+2, mid+1, high);

    seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
}

//int query(int ind, int low, int high, int l, int r)
//{
//    if(low>=l && high<=r)
//        return seg[ind];
//    if(high<l || low > r)
//        return INT_MIN;
//    int mid = (low+high)/2;
//    int left = query(2*ind+1, low, mid, l, r);
//    int right = query(2*ind+2, mid+1, high, l, r);
//    return max(left, right);
//}



int query(int ind, int low, int high, int l, int r)
{
    if(high < l || low > r) return INT_MIN;
    if(low>=l && high<=r)
        return seg[ind];
    int mid = (low+high)/2;

    int left = query(2*ind+1, low, mid, l, r);
    int right = query(2*ind+2, mid+1, high, l, r);
    return max(left, right);
}

int main() {
/*
#ifndef ONLINE_JUDGE
    //for getting input form intput.txt
    freopen("segment_treeip.txt", "r", stdin);
    //for writing output to output1.txt
    freopen("segment_treeop.txt", "w", stdout);
#endif
*/
    int n, temp;
    vector<int> arr;

    // cout << "enter number of values" << endl;
    cin >> n;
    // cout << "you entered: " << n << endl;
    // cout << "Enter " << n << " values" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    for(auto val: arr)
        cout << val << " ";
    cout << endl;

    build(arr, 0,0, n-1);

    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;

        cout << "max element in range (" << l << " to " << r<<") = " << query(0,0, n-1, l, r) << endl;
    }
    return 0;

}