/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

//l + r == tc
//tc - l == r

/*
vector<int> piles;

unordered_map<long long int,int> memo;



long long int hash(int l,int r){
    long long int h = l;

    h <<=sizeof(int)*8;
    h |= r;

    return h;    
}
    int dp(int l=0,int turnCount=0){
        int r = turnCount - l;
        long long int h = hash(l,r);
        if (memo.count(h)){
            return memo[h];
        }
        if (l == r){
            memo[h] = piles[l];
            return piles[l];
        }

        int lChoice = piles[l] - dp(l+1,turnCount + 1);

        int rChoice = piles[r] - dp(l,turnCount + 1);

        int res = max(lChoice,rChoice);
        memo[h] = res;
        return res;
    }
*/

    bool stoneGame(vector<int>& piles) {
        int turnCount = piles.size();
        vector<vector<int>>memo(turnCount,vector<int>(turnCount,0));
        for (int l = 0;l< turnCount;l++){
            memo[l][turnCount-1] = piles[l];
        }
        for (int turn = turnCount-2;turn >= 0;turn--){
            for (int left = 0;left <= turn;left++){
                int right = turnCount - left -1;
                int lChoice = piles[left] - memo[left+1][turn + 1];
                int rChoice = piles[right] - memo[left][turn + 1];
                int res = max(lChoice,rChoice);
                memo[left][turn] = res;
            }
        }
        return (max(memo[0][0],memo[turnCount-1][0]) >= 0);
    }
};
// @lc code=end
/*
class Solution {
public:
    bool stoneGame(vector<int>& piles) {

        int scores[2] = {0,0};
        int * aliceScore = &scores[0];
        int * bobScore = &scores[1];

        int l = 0;
        int r = piles.size()-1;

        int turn = 0;
        while (l < r-1){
            int lScore = piles[l]-;
            //take from left

            //opponent either takes from left 
            

            int rScore = piles[r]-(piles[r-1]);


            if (lScore > rScore){
                scores[turn%2] += piles[l];
                l++;
            }
            else{
                scores[turn%2] += piles[r];
                r--;
            }
            turn ++;
        }


        return *aliceScore > *bobScore;
    }
};

*/


