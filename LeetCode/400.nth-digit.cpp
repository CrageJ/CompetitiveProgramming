/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
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
    int findNthDigit(int n) {

        int lenValue = 1; // length of range
        int widthValue = 9; //countOfIndice
        
        ll res = 0;
        int iter = 0;
        //find to what value n is to the power of 10
        while (n > 9){
            res += 9*pow(10,iter);
            n/=2;
            iter++;
        }
        res += n*pow(10,iter);

        
    }
};
// @lc code=end

