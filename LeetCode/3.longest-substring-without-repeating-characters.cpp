/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        if (s.size()<2){
            return s.size();
        }
        int left = 0;
        int right = 1;
        
        int strlen = s.size();

        set<char>charset;
        charset.insert(s[0]);

        int maxlen =1;
        while (right != s.size()){

            char leftchar = s[left];
            char rightchar = s[right];

            //if they are on top of each other
            if (left >= right){
                charset.insert(rightchar);
                right++;
                continue;
            }

            //if there are repeats
            if (charset.count(rightchar) > 0){
                charset.erase(leftchar);
                left++;
                continue;
            }

            //if start > end and there are no repeats
            charset.insert(rightchar);
            right++;
            maxlen = max(maxlen,right-left);

        }
        return maxlen;
    }
};
// @lc code=end

