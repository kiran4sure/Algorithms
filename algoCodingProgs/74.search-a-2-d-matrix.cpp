/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
// #include <algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool result = false;

        vector<int>::iterator l1,l2;

         l1 = std::lower_bound(matrix[0].begin(), matrix[0].end(), 30);
         if(*l1 == target )
            return true;
         else
         {
             false;
         }

    }
};
// @lc code=end

