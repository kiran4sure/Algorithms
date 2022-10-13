/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
// vector<int> values{1000,900,500,400,100,90,50,40,10,9,5,4,1};
   vector<int> values{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000}; 
    // vector<string> symbols{"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
vector<string> symbols{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    string intToRoman(int num) {
        string res = "";
        while(num>0){
            int index = lower_bound(values.begin(), values.end(), num) - values.begin();
            // cout << "num = " << num << endl;
            // cout << "index = " << index << ", value = " << values[index] << ", symbol = " << symbols[index] << endl;
            
            index = index>=values.size()?index-1:values[index]==num?index:index-1;
            cout << "index = " << index << ", value = " << values[index] << ", symbol = " << symbols[index] << endl;
            cout << "==========" << endl;
            // for(int i=0;i<values.size();i++){
                // if(values[i]<=num){
                    res.append(symbols[index]);
                    num-=values[index];
                    // break;
                // }
            // }
        }
        return res;
        
    }
};

int main()
{
    Solution sln;
    cout << sln.intToRoman(1994) << endl;

    return 0;
}

