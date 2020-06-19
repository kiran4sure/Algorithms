/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here

#include <bits/stdc++.h>
using namespace std;

void print_data(int arr[], int n)
{
    stack<int> st;

    for(int i=1; i<=n; i++)
    {
        while(!st.empty() && arr[i]>arr[st.top()])
        {
            st.pop();
        }
        if(!st.empty())
            cout << i - st.top() << " ";
        else
            cout <<  i << " ";
        st.push(i);
        queue<int> q;
        q.
    }
    cout << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    //for getting input form intput.txt
    freopen("input1.txt", "r", stdin);
    //for writing output to output1.txt
    freopen("output1.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n+1];
        for(int i=1; i<=n; i++)
        {
            cin >> arr[i];
        }

        print_data(arr, n);
    }
    return 0;
}