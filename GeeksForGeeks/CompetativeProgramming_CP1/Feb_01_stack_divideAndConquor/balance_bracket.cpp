
#include <bits/stdc++.h>
using namespace std;

/*
	check if opening and closing brackets are balanced or in sync.

	eg: {(<>)} is balanced
		{(()}) is not balanced
*/

bool validate_bracket(string &s, unordered_map<char, char> &ip, unordered_map<char, char> &op)
{
	stack<char> st;

	for (char c : s)
	{
		if (ip.count(c))
		{
			st.push(c);
		}
		else if (op.count(c))
		{
			if (st.top() == op[c])
				st.pop();
			else
				return false;
		}
	}

	if (st.size() == 0)
		return true;
	else
		return false;
}


int main() {
#ifndef ONLINE_JUDGE
	//for getting input form intput.txt
	freopen("balance_bracket.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("balance_bracket_op.txt", "w", stdout);
#endif

	string s;
	unordered_map<char, char> ip, op;
	ip.insert({'{', '}'});
	ip.insert({'(', ')'});
	ip.insert({'[', ']'});
	ip.insert({'<', '>'});

	op.insert({'}', '{'});
	op.insert({')', '('});
	op.insert({']', '['});
	op.insert({'>', '<'});

	cin >> s;

	bool result = validate_bracket(s, ip, op);

	if (result)
		cout << s << " --> is balanced." << endl;
	else
		cout << s << " ---> is not balanced." << endl;
	return 0;

}