#include <bits/stdc++.h>
using namespace std;


void reverse_arr(int arr[], int index)
{
	if (index < 0)
		return;

	cout << arr[index] << endl;
	reverse_arr(arr, index - 1);
}


int main() {
#ifndef ONLINE_JUDGE
	//for getting input form intput.txt
	freopen("input1.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	reverse_arr(arr, n - 1);
	return 0;

}