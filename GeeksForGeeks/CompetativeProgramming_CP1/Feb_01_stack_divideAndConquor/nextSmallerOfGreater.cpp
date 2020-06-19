#include <bits/stdc++.h>
using namespace std;

/*
 * have to print the next smallest of the next greatest element
 * of the given array. in simple have to find the next greatest of
 * all the elemnts and then for each next greatest have to find the
 * next smallest
 *
 * */
void nextGreaterElement(vector<int> &arr, vector<int> &nsge, vector<int> &nge, vector<int> &nse)
{
    stack<int> st;
//    vector<int> nse(arr.size(), 0);
//    vector<int> nge(arr.size(), 0);
    //NextGreaterElement
    for(int i = arr.size()-1; i >=0 ; i--)
    {
        if(st.empty())
        {
            nge[i] = -1;
            st.push(i);
        } else{
            while(!st.empty() && arr[i] > arr[st.top()])
                st.pop();
            if(st.empty())
                nge[i] = -1;
            else
                nge[i] = st.top();
            st.push(i);
        }
    }

    //clear stack for reuse
    while(!st.empty()) st.pop();

    //Next smaller element

    for(int i = arr.size()-1; i >=0 ; i--)
    {
        if(st.empty())
        {
            nse[i] = -1;
            st.push(arr[i]);
        } else{
            while(!st.empty() && arr[i] < arr[st.top()])
                st.pop();
            if(st.empty())
                nse[i] = -1;
            else
                nse[i] = st.top();
            st.push(arr[i]);
        }
    }

    //deduce next smaller element of the next greater element
    for(int i=0; i<arr.size(); i++)
    {
        if(nge[i] == -1)
            nsge[i] = -1;
        else
            nsge[i] = nse[(nge[i])];
    }
}

int main() {
#ifndef ONLINE_JUDGE
    //for getting input form intput.txt
    freopen("nextSmallerOfGreater_ip.txt", "r", stdin);
    //for writing output to output1.txt
    freopen("nextSmallerOfGreater_op.txt", "w", stdout);
#endif

    int n, temp;
    vector<int> arr;
    cin >> n;
    vector<int> nsge(n,0);
    vector<int> nge(n,0);
    vector<int> nse(n,0);
    for(int i=0; i<n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }

    nextGreaterElement(arr, nsge, nge, nse);
//    for(int i=0; i<n; i++)
//    {
//        cout << arr[i] << " = " << (nge[i]==-1?-1:arr[nge[i]]) << " = "<<nse[i] << " = "<< nsge[i] << endl;
//    }

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "==Array==" << endl;

    for(int i=0; i<n; i++)
    {
        cout << (nge[i]==-1?-1:arr[nge[i]]) << "\t";
    }
    cout << "==NGE==" << endl;

    for(int i=0; i<n; i++)
    {
        cout << nse[i] << "\t";
    }
    cout << "==NSE==" << endl;

    for(int i=0; i<n; i++)
    {
        cout << nsge[i] << "\t";
    }
    cout << "==Next small of Next greater Element==" << endl;

    return 0;

}
