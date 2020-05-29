
#include <bits/stdc++.h>
using namespace std;

/*
	binary serach using recursion
*/

int bin_search_rec(vector<int> &v, int num, int low, int high)
{
	if (low > high) return -1;

	int mid = (low + high) / 2;

	if (v[mid] == num) return mid;

	if (v[mid] > num) return bin_search_rec(v, num, low, mid - 1);

	return bin_search_rec(v, num, mid + 1, high);
}


int main() {
#ifndef ONLINE_JUDGE
	//for getting input form intput.txt
	freopen("bin_srch_inp.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("bin_srch_op.txt", "w", stdout);
#endif

	int num, n, temp, result;
	vector<int> v;

	cin >> num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	result = bin_search_rec(v, num, 0, n - 1);

	cout << "binaray search of " << num << " = " << result << endl;

	return 0;

}
