
#include <bits/stdc++.h>
using namespace std;

/*
	Get the longest subarray of balanced numbers(can be brackets also)
	a number is said to be balanced if it has its negative counterpart.

	eg: 2, 1, -1, -2, 3, -3
		longest subarray is 4: 2,1,-1,2
		3, -3 cannot be included because, its balanced but it does not belong
		to this sub array its like (())(), same as above

*/

int LbalSubArr(vector<int> &arr)
{
	int Llength = 0;
	stack<int> st;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > 0)
			st.push(i);
		else if (arr[i] < 0)
		{
			if (st.size() && arr[st.top()] == -arr[i])
			{
				Llength = max(Llength, i - st.top() + 1);
				st.pop();
			}
			else
			{
				while (st.size())
					st.pop();
			}
		}
	}

	return Llength;
}


int main() {
#if 0
#ifndef ONLINE_JUDGE
	//for getting input form intput.txt
	freopen("LongestBalancedSubArray_ip.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("LongestBalancedSubArray_op.txt", "w", stdout);
#endif
#endif

	int n, temp;
	vector<int> arr;
	cout << "Enter number of elements to process:" <<  endl; 
	cin >> n;
	cout << "Enter " << n << " elements" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	int length = LbalSubArr(arr);

	cout << "length of longest sub array = " << length << endl;

	return 0;

}