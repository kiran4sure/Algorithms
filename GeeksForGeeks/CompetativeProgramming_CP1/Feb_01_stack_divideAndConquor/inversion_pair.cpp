
#include <bits/stdc++.h>
using namespace std;

/*
	count the number of inversions in the given array.
	An inversion states that the pairs i,j where j>i and a[i] > a[j]
	basically in simple words, left side nubmer is greater than the right side

	eg: arr = {5, 1, 3, 2}
	1, 3
	1, 2

	o/p: pairs = 2
*/

int cnt = 0;

void merge(int arr[], int l, int m, int r, vector<pair<int, int>> &vec)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 =  r - m;

	/* create temp arrays */
	int L[n1], R[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray
	j = 0; // Initial index of second subarray
	k = l; // Initial index of merged subarray
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
			cnt += (m - i + 1);
			int tp = i;
			while (m >= tp)
			{
				vec.push_back({L[tp], R[j - 1]});
				tp++;
			}
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;

	}
}

// void merge(int a[], int low, int mid, int high, vector<pair<int, int>> &vec)
// {
// 	int temp[high - low + 1];
// 	int i = low, j = mid + 1;
// 	int k = 0;
// 	while (i <= mid && j <= high)
// 	{
// 		cout << "============" << endl;
// 		if (a[i] <= a[j])
// 		{
// 			temp[k++] = a[i];
// 			i++;
// 		}
// 		else
// 		{
// 			temp[k++] = a[j];
// 			j++;
// 			// cnt += (mid - i + 1);
// 			// int tp = i;
// 			// while (mid >= tp)
// 			// {
// 			// 	cout << "	tp = " << tp << ", j-1 = " << j - 1 << endl;
// 			// 	for (int i = 0; i < 4; i++)
// 			// 	{
// 			// 		cout << a[i] << " ";
// 			// 	}
// 			// 	cout << endl;
// 			// 	cout << a[tp] << ", " << a[j - 1] << endl;
// 			// 	vec.push_back({a[tp], a[j - 1]});
// 			// 	tp++;
// 			// }
// 		}
// 	}

// 	while (i <= mid)
// 	{
// 		temp[k++] = a[i++];
// 	}

// 	while (j <= high)
// 	{
// 		temp[k++] = a[j++];
// 	}

// 	k = 0;
// 	for (int ii = low; i <= high; i++)
// 	{
// 		cout << temp[k] << " ";
// 		a[ii] = temp[k++];
// 	}
// 	cout << endl;

// 	for (int i = 0; i < 4; i++)
// 	{
// 		cout << a[i] << " ";
// 	}
// 	cout << endl;

// }


void mergeSort(int a[], int low, int high, vector<pair<int, int>> &vec)
{
	if (low >= high) return;
	int mid = (low + high) >> 1;

	mergeSort(a, low, mid, vec);
	mergeSort(a, mid + 1, high, vec);

	// cout << "low = " << low << " mid = " << mid << " high = " << high << endl;
	merge(a, low, mid, high, vec);

}


int main() {
#ifndef ONLINE_JUDGE
	//for getting input form intput.txt
	freopen("inversion_pair_ip.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("inversion_pair_op.txt", "w", stdout);
#endif

	int n, temp;
	vector<pair<int, int> > vec;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr[i] = temp;
	}


	mergeSort(arr, 0, n - 1, vec);

	cout << "number of inversion pairs = " << cnt << endl;

	for (pair<int, int> i : vec)
	{
		cout << "(" << i.first << ", " << i.second << ")" << endl;
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;

}