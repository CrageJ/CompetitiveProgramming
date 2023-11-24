/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
struct PairHash {
    std::size_t operator()(const std::pair<T, T>& p) const {
        auto hash1 = std::hash<T>{}(p.first);
        auto hash2 = std::hash<T>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
//num , count
        unordered_map<int,int> memo;

        for (auto n:nums){
            if(memo.count(n)>0){
                memo[n] ++;
            }
            else{
                memo[n] = 0;
            }
        }

        vector<pair<int,int>> arr;
        for (auto m:memo){
            arr.push_back({m.first,m.second});
        }

        sort(arr.rbegin(),arr.rend(),[](const pair<int,int> l,const pair<int,int> r){
            return l.second < r.second;
        });

        vector<int> result;
        for (auto a:arr){
            result.push_back(a.first);
        }

        result= {result.begin(),result.begin()+k};
        return result;

        
    }
};
// @lc code=end

