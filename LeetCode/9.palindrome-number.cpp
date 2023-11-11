/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(int x) {
        if (x<0 ){
            return false;
        }
        if (x < 10){ 
            return true;
        }

        vector<int> v;

        while (x > 9){
            v.push_back(x%10);
            x/=10;
        }
        v.push_back(x);


        for (int i = 0;i< (v.size()/2);i++){
            //cout<<v[i]<<" "<<v[v.size()-i-1];
            if (v[i] != v[v.size()-i-1]){
                return false;
            }
        }
        return true;

        
    }
};
// @lc code=end

