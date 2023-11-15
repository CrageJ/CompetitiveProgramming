/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0,r = nums.size()-1;
        int m;

        while (l != r){
            int left = nums[l];
            int right = nums[r];
            m = (l+r)/2;
            int middle = nums[m];

            if (left > right){
                if (middle > left){
                    l = m;
                }
                else if (middle < right){
                    r=m;
                }
                else{
                    l = l+1;

                    l = l%(nums.size());
                    
                    return nums[l];
                }
            }
            else{
                r=m;
            }
            //if right > left
            
        }       

        return nums[l];

    }
};
// @lc code=end

