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

/*
 * @lc app=leetcode id=1630 lang=cpp
 *
 * [1630] Arithmetic Subarrays
 */

// @lc code=



class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result(l.size(),true);
        for (int i = 0;i< l.size();i++){
            vector<int> ins(nums.begin()+l[i],nums.begin()+r[i]+1); // is it ptr + 1?
            sort(ins.begin(),ins.end());
            int distance = ins[1]- ins[0];
            bool isValid = true;
            for (int j = 1;j< ins.size();j++){
                if (ins[j] - ins[j-1] != distance){
                    result[i] = false;
                    break;
                }
            }
        }
        return result;
    }
};
// @lc code=end

