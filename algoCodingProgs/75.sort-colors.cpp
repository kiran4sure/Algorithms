/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include<vector>
using namespace std;


class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int first =0, mid = 0, last = nums.size()-1;

        while(mid <= last)
        {
            switch(nums[mid])
            {
                case 0:
                    swap(nums[first++], nums[mid++]);
                    break;

                case 1:
                    mid++;
                    break;
                
                case 2:
                    swap(nums[mid], nums[last--]);
                    break;
            }
        }
    }
};
// @lc code=end

