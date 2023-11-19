
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isBadVersion(int version);

/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;

        while (l < r){
            int mid = (l)/2 + (r)/2 + (l%2 &&r%2 );
            bool middle = isBadVersion(mid);
            bool left = isBadVersion(l);
            bool right = isBadVersion(r);
            if (left == false &&  isBadVersion(l+1) == true){
                return l+1;
            }
            if (middle == true){
                r = mid;
            }
            else{
                l = mid;
            }
        }

        return l;

        
        
    };
};
// @lc code=end

