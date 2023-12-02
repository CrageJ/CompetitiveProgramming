/*
 * @lc app=leetcode id=1611 lang=cpp
 *
 * [1611] Minimum One Bit Operations to Make Integers Zero
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

    vector<int> powers;
    int minimumOneBitOperations(int n) {
       if (n < 2){
        return n;
       }

       int count = 0;
       
        for (int i = 2;i<1000000000;i*=2){
            powers.push_back(i);
        }
        //powers.push_back(1);

       while (n != 0){
            int k = n;
            while (k != 0){
                
            }
            n/=2;
       }


       return count;

        




    }
};
// @lc code=end

