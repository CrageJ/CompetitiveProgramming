/*
 * @lc app=leetcode id=1630 lang=cpp
 *
 * [1630] Arithmetic Subarrays
 */

// @lc code=

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
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<vector<int>> v;
        for (int i = 0;i< l.size();i++){
            int ptrL = l[i];
            int ptrR = r[i];

            
            vector<int> ins(nums.begin()+ptrL,nums.begin()+ptrR+1); // is it ptr + 1?
            v.push_back(ins);
            
        }

        vector<bool> result;

        for (auto &item : v){
            sort(item.begin(),item.end());
            int distance = item[1]- item[0];
            for (int i = 1;i< item.size();i++){
                if (item[i] - item[i-1] != distance){
                    result.push_back(false);
                    goto jmp;
                }
            }
            result.push_back(true);
            jmp:
            continue;
        }

        return result;
    }
};
// @lc code=end

