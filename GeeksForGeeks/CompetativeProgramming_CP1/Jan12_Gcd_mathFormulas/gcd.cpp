#include <bits/stdc++.h>
using namespace std;


/*get the minimum of the 2 mumers and go from the decreasing order and check with 
which number both the nunber gets divided and thats the GCD
time complixity is O(N), min(n)*/
int gcd_bruteForce(int n1, int n2)
{
    for(int i = min(n1,n2); i >= 1; i--)
    {
        if((n1 % i == 0) && (n2 % i == 0))
            return i;
    }
}
/*Euclidean alogrithm: get modulus of greater number with smaller number
 * number until you get one nubmer as 0 and the remaining is the GCD
 * we use mod to minimize the repetaive substraction */
int gcd_optimized(int n1, int n2)
{
	if(n1 == 0) return n2;
	return gcd_optimized(n2%n1, n1);
}

int main()
{
    int n1, n2;
    cout << "Enter 2 numbers for GCD:" << endl;
    cin >> n1 >> n2;
    cout << "brute force GCD of " << n1 << " and " << n2 << " = " << gcd_bruteForce(n1, n2) << endl;
    cout << "Euclidean GCD " << n1 << " and " << n2 << " = " << gcd_bruteForce(n1, n2) << endl;
    
    //inbult gcd in STL C++
    int g = __gcd(n1, n2);
    cout << "Inubuilt STL GCD  = " << g << endl;
    return 0;
}
