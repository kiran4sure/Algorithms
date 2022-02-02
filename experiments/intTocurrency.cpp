#include <iostream>
#include <string>


using namespace std;


class intToCur
{
    string lessThan20[20] = {"","One","Two","Three","Four","Five","Six","Seven","Eight",
                                  "Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen",
                                  "Sixteen","Seventeen","Eighteen","Nineteen"};
    string tens[10] = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string thousands[10] = {"","Thousand","Million","Billion"};

public:
    string getInr(int num)
    {
        if(num == 0)
            return "Zero";

        int idx = 0;
        string amount;
        while(num%1000 != 0)
        {
            amount 
        }

        
    }


    string helper(int num)
    {
        return "";
    }

};




int main()
{
    intToCur currency;
    string amount = currency.getInr(0);

    cout << amount << endl;

    return 0;
}