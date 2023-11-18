/*
 * @lc app=leetcode id=1877 lang=cpp
 *
 * [1877] Minimize Maximum Pair Sum in Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int l = 0;
        int r = 0;

        int res = 0;
        for (int i = 0;i< nums.size()/2;i++){
            res = max(res,nums[i]+nums[nums.size()-i-1]);
        }        

        return res;
    }
};
// @lc code=end

