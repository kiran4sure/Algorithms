/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

const char* w = " \t\n\r\f\v";

// trim from end of string (right)
inline std::string& rtrim(std::string& s)
{
    s.erase(s.find_last_not_of(w) + 1);
    return s;
}

class Solution {
public:
    string lessThan20[20] = {"","One","Two","Three","Four","Five","Six","Seven","Eight",
                            "Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen",
                                  "Sixteen","Seventeen","Eighteen","Nineteen"};
    string tens[10] = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string thousands[5] = {"","Thousand","Million","Billion"};
    
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        string word="";
        int idx=0;
        
        while(num>0){
            if(num%1000!=0)
                word = helper(num%1000)+thousands[idx]+" "+word;
            num=num/1000;
            idx++;
        }
        rtrim(word);
       return word; 
    }
    
    string helper(int num){
        if(num==0)
            return "";
        if(num<20)
            return lessThan20[num]+" ";
        else if(num<100)
            return tens[num/10]+" "+helper(num%10);
        else
            return helper(num/100)+"Hundred "+helper(num%100);
    }
};

int main()
{
    Solution sln;
    string res = sln.numberToWords(3492567);
    cout << res << endl; 

    return 0;
}

