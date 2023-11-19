#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        if (s.size() == 1) return false;

        string sub;

        for (int start=0;start<=s.size()/2;start++){
            sub += s[start];

            // do length checks
            if (s.size()%sub.size() != 0 || sub.size() * 2 > s.size() ){
                continue;
            }

            

            for (int track = start+1;track<s.size();track++){
                if (sub[track%sub.size()] != s[track]){
                    goto jump;
                }
            }
            return true;


            jump:
            continue;
        }

        return false;

    }
};
// @lc code=end

