/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int guess(int num);



// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int r = n;

        while (l < r){
            int m = l/2 + r/2 + (l%2==1&&r%2==1);
            int mid = guess(m);
            if (mid == 0){
                return m;
            }
            if (guess(r) == 0){
                return r;
            }
            //num > pick
            if (mid == 1){
                l = m;
                continue;
            }
            //num < pick
            if (mid == -1){
                r = m;
                continue;
            }
        }

        return l;
    }
};
// @lc code=end

