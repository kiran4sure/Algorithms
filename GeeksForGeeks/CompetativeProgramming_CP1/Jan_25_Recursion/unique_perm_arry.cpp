
#include <bits/stdc++.h>
using namespace std;

/*
	print the unique permutations of the given array in sorted order
	so it will be !n o/p's
	eg: arr = {2,1,3}
	op: {1,2,3}
		{1,3,2}
		{2,1,3}
		{2,3,1}
		{3,1,2}
		{3,2,1}
*/

void unique_perm(vector<int> &v, vector<int> &combinations, unordered_set<int> &st)
{
	if (combinations.size() > v.size()) return;
	if (combinations.size() == v.size())
	{
		for (auto i : combinations)
			cout << i << " ";
		cout << endl;
		return;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (!st.count(i))
		{
			st.insert(i);
			combinations.push_back(v[i]);
			unique_perm(v, combinations, st);
			combinations.pop_back();
			st.erase(i);
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	//for getting input form intput.txt
	freopen("unique_perm_arry_ip.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("unique_perm_arry_op.txt", "w", stdout);
#endif

	int n, temp;
	vector<int> v, combinations;
	unordered_set<int> st;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	cout << " array size = " << v.size() << endl;
	unique_perm(v, combinations, st);
	return 0;

}