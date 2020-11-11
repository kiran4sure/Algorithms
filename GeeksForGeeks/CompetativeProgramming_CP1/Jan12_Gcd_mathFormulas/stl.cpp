#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a[] = {5,6,7,7,6,5,5,6,4,2,4,1,4};
	int n = sizeof(a)/sizeof(a[0]);

	/*Lower bound and upper bound are inbuilt binary search in STL
	 * so in order to use them, container should be sorted*/

	sort(a, a+n);
	cout << "array:" << endl;
	for(auto ele: a)
		cout << ele << " ";
	cout << endl;
	/*lower bound returns the iterator the element 
	 * if present or next greater elemennt
	 * this returns the iterator to the first occurance*/
	int *lb = lower_bound(a, a+n, 4);
	int elemLB = lower_bound(a, a+n, 4) - a;

	/*upper bound returns the iterator to next greater element, if it is out of bound, returns iterator to end()*/
	int *ub = upper_bound(a, a+n, 4);
	int elemrUB = upper_bound(a, a+n, 4) - a;
	
	cout << "*lb = " << *lb << ". elemLB = " << elemLB << ", *ub = " << *ub << ", elemrUB = " << elemrUB << endl;  

	return 0;
}

