#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        s = ' ' + s + ' ';
        int lastSpace = 0;
        for (int i = 1;i< s.size();i++){
            if (s[i] == ' '){
                int span = i -lastSpace;
                for (int j = 0; j <= (span)/2 ;j++){
                    swap(s[lastSpace+j],s[lastSpace + span - j]);
                }
                lastSpace = i;
            }
        }

        return s.substr(1,s.size()-2);
    }
};
// @lc code=end

