/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
#include <string>
#include <map>
#include <stack>
// @lc code=start
using namespace std;
class Solution {
public:
    int romanToInt(string s) {

        if(s.length() == 0)
            return 0;
        map<char, int> mp = {{'I', 1},
                             {'V', 5},   
                             {'X', 10},   
                             {'L', 50},   
                             {'C', 100},   
                             {'D', 500},   
                             {'M', 1000},   
                                };
        
        int value = 0;

        stack<int> st;

        st.push(mp[s[0]]);

        for(int i=1; i< s.length(); i++)
        {
            int current = mp[s[i]];
            while(!st.empty() && current > st.top())
            {
                current = current - st.top();
                // value += current;
                st.pop();
                
            }
            st.push(current);
        }

        while(!st.empty())
        {
            value+=st.top();
            st.pop();
        }        

        return value;

    }
};
// @lc code=end

