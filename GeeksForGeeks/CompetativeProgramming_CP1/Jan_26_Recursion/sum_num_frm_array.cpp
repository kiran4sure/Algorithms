
#include <bits/stdc++.h>
using namespace std;

/*
	print the sum of elements from the array to get the value of given number.
	order should be in sorted order.
	combination should be unique.
	eg:
	arr = [1,3,6,2,4,8];
	num = 4
	[1,2,1]
	[1,1,2] cannot be, since 1,1, 2 are already there
*/

void printComboSums(vector<int> &v, int target, vector<int> &combinations, set<vector<int>> &st)
{
	if (target < 0) return;

	if (target == 0)
	{
		if (!st.count(combinations))
		{
			st.insert(combinations);
			for (auto i : combinations)
				cout << i << " ";
			cout << endl;
		}
		return;
	}

	for (int i = 0; i < v.size(); i++)
	{
		combinations.push_back(v[i]);
		printComboSums(v, target - v[i], combinations, st);
		combinations.pop_back();
	}
}


int main() {
#ifndef ONLINE_JUDGE
	//for getting input form intput.txt
	freopen("arr_sum_ip.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("arr_sum_op.txt", "w", stdout);
#endif

	int n, temp, target;
	vector<int> v, combinations;
	set <vector<int>> st;

	cin >> target;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	printComboSums(v, target, combinations, st);
	return 0;

}