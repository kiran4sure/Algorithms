
#include <bits/stdc++.h>
using namespace std;

/*
	have to verify if string is palindrome or not
*/

bool isPalindrome(string inp, int start, int end)
{
	if (start > end) return true;

	if (inp[start] == inp[end]) return isPalindrome(inp, start + 1, end - 1);
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	//for getting input form intput.txt
	freopen("pal_inp.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("pal_op.txt", "w", stdout);
#endif

	string inp;
	cin >> inp;
	bool result = false;

	result = isPalindrome(inp, 0, inp.length() - 1);
	if (result)
		cout << inp << " is a palindrome"  << endl;
	else
		cout << inp << " is not a palindrome"  << endl;

	return 0;

}