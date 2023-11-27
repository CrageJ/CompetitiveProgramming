/*
 * @lc app=leetcode id=483 lang=cpp
 *
 * [483] Smallest Good Base
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
    string smallestGoodBase(string n) {

        
        

        
    }
};
// @lc code=end

