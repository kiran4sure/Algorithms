
#include <bits/stdc++.h>
using namespace std;

/*
	print the sum of all natural number which adds up to the given number
	and the order should be sorted
*/

void sum_num(int result, vector<int> &combinations)
{
	if (result < 0) return;
	if (result == 0)
	{
		for (auto i : combinations)
			cout << i << " ";
		cout << endl;
	}

	for (int i = 1; i <= result; i++)
	{
		combinations.push_back(i);
		sum_num(result - i, combinations);
		combinations.pop_back();
	}

}

int main() {
#ifndef ONLINE_JUDGE
	//for getting input form intput.txt
	freopen("sum_num_ip.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("sum_num_op.txt", "w", stdout);
#endif

	int n;
	vector<int> combinations;
	cin >> n;
	sum_num(n, combinations);
	return 0;

}