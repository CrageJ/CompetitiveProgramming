/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0){
            return true;
        }
        int placed = 0;

        for (int i = 0 ;i< flowerbed.size() && placed < n;i++){
            if (flowerbed[i] == 1){
                i++;//skip ahead 2 instead of one
                continue;
            }
            bool canPlace = true;
            
            if (i<flowerbed.size()-1){
                if (flowerbed[i+1] == 1){
                    i+= 2; //skip ahead 3 instead of one;
                    canPlace = false;
                }
            }

            if (i > 0){
                if (flowerbed[i-1] == 1){
                    canPlace = false;
                }
            } 

            if (canPlace){
                placed++;
                i++; //skip ahead 2 instead of one
            }
        }
        return placed >= n;
    }
};
// @lc code=end
/*
original solution
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0){
            return true;
        }
        if (flowerbed.size() == 1){
            if (n == 1 && flowerbed[0] == 0){
                return true;
            }
            return false;
        }

        int placed = 0;

        //lhs
        if (flowerbed[0] == 0 && flowerbed[1]==0){
            placed++;
            flowerbed[0] = 1;
        }

        //rhs
        if (flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] == 0){
            placed++;
            flowerbed[flowerbed.size()-1] = 1;
        }

        for (int i = 1 ;i< flowerbed.size()-1;i++){
            if (flowerbed[i] == 1){
                i++;
                continue;
            }
            if (flowerbed[i-1] == 0 && flowerbed[i + 1] == 0){
                flowerbed[i] = 1;
                i++;
                placed++;
                continue;
            }
        }
        return placed >= n;
    }
};


*/


