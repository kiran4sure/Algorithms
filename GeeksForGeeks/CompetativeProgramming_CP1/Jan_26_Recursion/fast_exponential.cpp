#include <bits/stdc++.h>
using namespace std;

/*
	return a exponential of an number using fast exponential.

	explination.
	if n is even --> x * x^(n/2)
	if n is odd --> x*x^(n-1)
*/


int power(int base, int n)
{
	if (n == 0) return 1;

	if (n % 2 == 0) return power((base * base), n / 2);

	return (base * power(base, n - 1));
}

int main() {
#ifndef ONLINE_JUDGE
	//for getting input form intput.txt
	freopen("fast_exponential_ip.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("fast_exponential_op.txt", "w", stdout);
#endif

	int base, pow;
	cin >> base;
	cin >> pow;
	int result = power(base, pow);
	cout << result << endl;
	return 0;

}