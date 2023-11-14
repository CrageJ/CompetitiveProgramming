/*
 * @lc app=leetcode id=836 lang=cpp
 *
 * [836] Rectangle Overlap
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    bool isBinsideA(vector<int>& a, vector<int>& b){

        int ax1 = a[0],ay1=a[1],ax2=a[2],ay2=a[3];
        int bx1 = b[0],by1=b[1],bx2=b[2],by2=b[3];

        if (ax1 >= bx2 || bx1 >= ax2 || ay1 >= by2 || by1 >= ay2  ){
            return false;
        }
        return true;
        
    }


    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
       return isBinsideA(rec1,rec2) || isBinsideA(rec2,rec1);
        
    }
};
// @lc code=end

