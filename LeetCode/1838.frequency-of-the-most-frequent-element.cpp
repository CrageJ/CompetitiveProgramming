/*
 * @lc app=leetcode id=1838 lang=cpp
 *
 * [1838] Frequency of the Most Frequent Element
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int min = nums[0];

        for (auto & n : nums){
            n = n-min;
        }

        //sliding window
        int l = 0;
        int r = 1;

        //int prev = 0;
        vector<ll> rangeSum = {nums[0]};
        
        for (int i = 1;i< nums.size();i++){
            rangeSum.push_back(((ll)nums[i])+rangeSum[i-1]);
        }



        ll maxFreq = 1;
        while (r < nums.size()){
            //cout << "l r "<<l<<' '<<r<<endl;
            if (r == l){
                r++;
            }
            else{
                ll right = rangeSum[r];
                ll left = rangeSum[l];

                ll stepsSoFar = right - left + nums[l];

                //cout << "steps so far "<<stepsSoFar<<endl;

                ll range = r-l+1;

                ll kMoves = range*nums[r]- stepsSoFar; 

                
                if (kMoves <= k){
                    //cout << "kmoves <= k : "<<kMoves<<endl;
                    maxFreq = max(maxFreq,range);
                    r++;
                }
                else{
                    //cout << "kmoves > k : "<<kMoves<<endl;
                    l++;
                }
            }
        }

        return maxFreq;






    }
};
// @lc code=end

