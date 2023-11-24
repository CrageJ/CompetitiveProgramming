/*
 * @lc app=leetcode id=1561 lang=cpp
 *
 * [1561] Maximum Number of Coins You Can Get
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
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(),piles.end());
        //vector<int> order;
        int res=0;
        int l = 0,r = piles.size()-1;
        //take 2 from right, one from left
        // second right is your choice, alice r bob l
        while (l< r){
            r--;
            res += piles[r];
            r--;
            l++;
        }

        return res;
        
    }
};
// @lc code=end

