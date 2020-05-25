#include <bits/stdc++.h>
using namespace std;

/*
	givne a number, write the combination of turning on the 0 bits.
	we sholud not turn off the 1's

	eg: num = 1010

	op:
		1010
		1011
		1111
		1110
*/

void print_bits(int num, int count = 0)
{
	if (!num) return;

	print_bits(num >> 1, count + 1);
	cout << (num & 1);
	if (count % 4 == 0)
		cout << " ";
	if (count == 0)
		cout << endl;
}

void turn_on_bits(int num, unordered_set<int> &st)
{
	if (!st.count(num))
	{
		st.insert(num);
		print_bits(num);
	}

	for (int i = 0; i <= log2(num); i++)
	{
		if (!(num & (1 << i)))
		{
			turn_on_bits(num | (1 << i), st);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	//for getting input form intput.txt
	freopen("turn_on_bits_combi_ip.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("turn_on_bits_combi_op.txt", "w", stdout);
#endif

	int n;
	unordered_set<int> st;
	cin >> n;
	turn_on_bits(n, st);

	return 0;

}