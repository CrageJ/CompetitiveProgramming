

/*
 * @lc app=leetcode id=2405 lang=cpp
 *
 * [2405] Optimal Partition of String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

//using tail recursion
    int dp(string s,int carryover = 0){
        int result = 1 + carryover;

        int strlen = s.size();
        if (strlen == 0){
            return carryover;
        }
        set<char> characters;
        bool foundRepeat = false;
        for (int i = 0;i< strlen;i++){
            char c = s[i];
            if (characters.count(c) == 0){
                characters.insert(c);
                continue;
            }
            return dp(s.substr(i,strlen-(i)),result);
        }

        return result;
        
    }
    int partitionString(string s) {
        return dp(s);
    }
};
// @lc code=end

