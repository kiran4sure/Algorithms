
#include <bits/stdc++.h>
using namespace std;

/*
	print the number of possible ways to reach the end position in the maze/matrix

	eg:

	1 0 0 0
	0 1 0 0
	0 0 1 0
	0 0 1 1

	we can reach in 2 ways

   1 0 0 0   	1 0 0 0
   0 1 0 0   	0 1 0 0
   0 0 1 0   	0 0 1 0
   0 0 0 1   	0 0 1 1
*/

void print_mat(vector<vector<int>> &mat)
{
	for (auto v : mat)
	{
		for (auto i : v)
			cout << i << " ";
		cout << endl;
	}
}

int num_ways(vector<vector<int>> &mat, int row, int col)
{
	if (row >= mat.size() || col >= mat[row].size() || mat[row][col] == 0) return 0;

	if (row == mat.size() - 1 && col == mat[row].size() - 1)
		return mat[row][col];

	return num_ways(mat, row + 1, col) + num_ways(mat, row, col + 1) + num_ways(mat, row + 1, col + 1);
}

int main() {
#ifndef ONLINE_JUDGE
	//for getting input form intput.txt
	freopen("num_ways_matric_ip.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("num_ways_matric_op.txt", "w", stdout);
#endif

	int row, col, temp;
	cin >> row;
	cin >> col;
	vector<vector<int>> mat;

	for (int i = 0; i < row; i++)
	{
		mat.emplace_back();
		for (int j = 0; j < col; j++)
		{
			cin >> temp;
			mat[i].push_back(temp);
		}
	}

	print_mat(mat);

	int ways = num_ways(mat, 0, 0);

	cout << "matrix has " << ways << " number of ways" << endl;

	return 0;

}