#include <bits/stdc++.h>
using namespace std;

void nextGreatestElement(vector<int> &vec, vector<int> &nge)
{
	stack<int> st;

	for (int i = vec.size() - 1; i >= 0; i--)
	{
		if (st.empty())
		{
			nge[i] = -1;
			st.push(vec[i]);
		}
		else
		{
			while (!st.empty() && st.top() < vec[i])
				st.pop();

			if (!st.empty())
			{
				nge[i] = st.top();
			}
			else
			{
				nge[i] = -1;
			}

			st.push(vec[i]);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	//for getting input form intput.txt
	freopen("nextGreatestElement_ip.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("nextGreatestElement_op.txt", "w", stdout);
#endif

	int n, temp;
	vector<int> arr;
	cin >> n;
	vector<int> nge(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	nextGreatestElement(arr, nge);

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " = " << nge[i] << endl;
	}

	return 0;

}