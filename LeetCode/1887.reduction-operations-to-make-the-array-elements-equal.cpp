#include <bits/stdc++.h>
using namespace std;
typedef long long ll;





/*
 * @lc app=leetcode id=1887 lang=cpp
 *
 * [1887] Reduction Operations to Make the Array Elements Equal
 */

// @lc code=start
class Solution {
public:
    int reductionOperations(vector<int>& nums) {

        set<int> sset;

        int minValue = INT_MAX;
        for (auto num : nums){
            minValue = min(minValue, num);
            sset.insert(num);
        }

        vector<int> order(sset.begin(),sset.end());
        sort(order.begin(),order.end());

        //integer,position
        unordered_map<int,int> m;
        int idx = 0;
        for (auto num : order){
            m[num] = idx;
            idx++;
        }

        int result = 0;
        for (auto num:nums){
            result += m[num];
        }

        return result;

    }
};
// @lc code=end

