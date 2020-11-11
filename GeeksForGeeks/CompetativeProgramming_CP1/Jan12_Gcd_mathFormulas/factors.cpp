#include<bits/stdc++.h>

using namespace std;
/*
 *print factors of a given number N in a sorted order
 * 
 * */

void printFactors(int num)
{
	stack<int> factors;
	for(int i=1; i*i <= num; i++) //can use i*i to eliminate sqrt
	{
		if(num%i == 0)
		{
			cout << i << " ";
			int rem = num/i;
			if(i != rem)
				factors.push(rem);
		}
	}
		
	while(!factors.empty())
	{
		cout << factors.top() << " ";
		factors.pop();
	}

	cout << endl;
}

/*
 *formula for no of factors is product of power of prime factors + 1
 * eg: 20 = 2^2 x 5^1
 * 	= (2+1)x(1+1) = 3x2
 * 	= 6
 * 	
 * 	eg: 420 = 2x2x3x5x7 
 * 	 = 2^2 x 3^1 x 5^1 x 7^1
 * 	 = (2+1)x(1+1)x(1+1)x(1+1) = 3x2x2x2
 * 	 = 24
 *
 * */
int numOfFactors(int num)
{
	int ans = 1;

	/* prime factors starts from 2, since 1 is not a prime number
	 * */
	for(int i=2; num != 1; i++)
	{
		if(num%i == 0)
		{
			int cnt = 0;
			/*divide the number by prime factor until it is divisble
			 * eg: 420/2 = 210
			 * 210/2 = 105
			 * cnt = 2 +1
			 * 105/3 = 35
			 * cnt = 1+1
			 * 35/5 = 7
			 * cnt = 1+1
			 * 7/7 = 1
			 * cnt = 1+1
			 * factors = 3x2x2x2 = 24
			 * since we are diving by initial numbers eg:2, next it will 
			 * cover all factors of 2 like 4, 6, 8 .. so next divisible 
			 * will be a prime factor only
			 * */
			while(num%i == 0)
			{
				num = num/i;
				cnt++;
			}
			ans = ans * (cnt+1);
		}
	}
	return ans;
}


int main()
{
	int num;
	cout << "Enter a number:" << endl;
	cin >> num;

	printFactors(num);
	int numFact = numOfFactors(num);
	cout << "number of factors of " << num << " = " << numFact << endl; 
}
