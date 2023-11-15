/*
 * @lc app=leetcode id=1846 lang=cpp
 *
 * [1846] Maximum Element After Decreasing and Rearranging
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//modifies
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        sort(arr.begin(),arr.end());
        arr[0] = 1;

        for (int i = 1;i< arr.size();i++){
            int currMax = arr[i-1] + 1;
            // No change
            if (!(arr[i] <= currMax)){
                arr[i] = currMax;
            }
        }

        return arr[arr.size()-1];
              
    }
};
// @lc code=end

