#include<bits/stdc++.h>

using namespace std;


/*we have to check the divisibility of the number until square root of the 
 * number, if it divides then it is not a prime.
 * why till square root:
 * because after square root the numbers repeate on the other side of the
 * multiple.
 *
 * eg: 36
 * 1x36
 * 2x18
 * 3x12
 * 4x9
 * 6x6
 * ===
 * 9x4
 * 12x3
 * 18x2
 * 36x1
 *
 * if you observe, squrt(36) = 6 and after 6 numbers tend to repeat.
 *
 * */
bool check(int num)
{
    if(num == 1) return false;

    for(int i = 2; i<=sqrt(num); i++)
        if(num % i == 0) return false;
    return true;
}

int main()
{
    int num;
    cout << "Enter number to check prime:" << endl;
    cin >> num;
    string out = check(num)?"":"not "; 
    cout << num << " is " << out << "a prime number" << endl;
	return 0;
}
