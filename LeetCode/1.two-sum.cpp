/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> set;        
        for (int i = 0;i< nums.size();i++){
            int valueToFind = target - nums[i];
            if (set.count(valueToFind) > 0 ){
                return {i,set[valueToFind]};
            }
            set[nums[i]] = i;
        }

        return {0,1};
    }
};
// @lc code=end

