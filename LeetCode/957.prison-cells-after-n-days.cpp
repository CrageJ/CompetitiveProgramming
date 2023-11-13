/*
 * @lc app=leetcode id=957 lang=cpp
 *
 * [957] Prison Cells After N Days
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<int> previousPrisonCell(cells); 
        vector<int> currentPrisonCell(previousPrisonCell);

        for (int t = 0;t<n;t++){
            for (int i = 0;i<8;i++){
                currentPrisonCell[i] = 0;
                bool initialised = false;
                bool isLeftOccupied=false;

                if (i > 0){
                    initialised = true;
                    if (previousPrisonCell[i-1] == 1 ){
                        isLeftOccupied = true; 
                    }
                }
                if (initialised &&(i < 8-1)){
                    if (isLeftOccupied == previousPrisonCell[i+1]){
                        currentPrisonCell[i] = 1; 
                    }
                    
                }
                previousPrisonCell = currentPrisonCell;
        }
        }

        return currentPrisonCell;


    }
};
// @lc code=end

