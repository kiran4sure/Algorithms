#include <iostream>
#include <unordered_set>
#include <map>
#include <string>

using namespace std;


bool buddyStrings(string A, string B) {
    unordered_set<char> st;
    bool result = false;
    bool dbl = false;
    int count = 0;
    int nums[2] = {-1, -1};

    if(A.length() != B.length())
        return false;

    for(int i = 0; i < A.length(); i++)
    {
        if(st.count(A[i]))
            dbl = true;
        st.insert(A[i]);
        if(A[i] != B[i])
        {
            if(count <=1)
                nums[count] = i;
            count++;
        }
        if(count > 2)
            return false;
    }

    if((count == 0 && dbl==true) || ((nums[0] != -1 && nums[1] != -1) && ((A[nums[0]] == B[nums[1]]) && (A[nums[1]] == B[nums[0]]))))
        result = true;

    return result;
}




int main() {
    string A = "abcd";
    string B = "badc";

    bool res = buddyStrings(A, B);

    cout << res << endl;

    return 0;
}
