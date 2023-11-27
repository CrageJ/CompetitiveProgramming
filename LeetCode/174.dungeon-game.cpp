/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template <typename T>
struct PairHash {
    std::size_t operator()(const std::pair<T, T>& p) const {
        auto hash1 = std::hash<T>{}(p.first);
        auto hash2 = std::hash<T>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Solution {
public:
//vector<vector<int>> dungeon;
//vector<vector<int>> memo;
/*    //int dp(int x, int y){
        //oob errorif (y >= dungeon.size()||x>=dungeon[0].size()){
            return INT_MAX;
        }

        int health = dungeon[y][x];

        //end of dungeon case
        if (y == dungeon.size()-1 && x == dungeon[0].size()-1){
            if (health < 0){
                return (health*-1) + 1; // how much health do you need to survive this room?
            }
            return 1;
        }
        
        int down = dp(x,y+1);
        int r = dp(x+1,y);
        int res =  min(down,r);

        if (res == INT_MAX){
            return INT_MAX;
        }
        return max(res - health,1); // lowers health requirement
        
        
    }*/
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        //this->dungeon = dungeon;
        //memo.resize(dungeon.size(),vector<int>(dungeon[0].size(),INT_MIN));
        //return(dp(0,0));

        int xMax = dungeon[0].size();
        int yMax = dungeon.size();


        vector<vector<int>> memo(yMax,vector<int>(xMax,INT_MAX));

        memo[yMax-1][xMax-1] = max((dungeon[yMax-1][xMax-1] *-1) + 1,1);
        //cout<<memo[yMax-1][xMax-1]<<endl;
        
        for(int y = yMax-2;y>=0;y--){
            memo[y][xMax-1] = max(memo[y+1][xMax-1]-dungeon[y][xMax-1],1);
        } 
        for(int x = xMax-2;x>=0;x--){
            memo[yMax-1][x] = max(memo[yMax-1][x+1]-dungeon[yMax-1][x],1);
        } 

        for(int y = yMax-2;y>=0;y--){
            for (int x = xMax-2;x>=0;x--){
                int res = memo[y][x];

                
                    res = min(res, memo[y][x+1]);
             
                
                    res = min(res, memo[y+1][x]);
           
                if (x == xMax-1 &&yMax-1 == y){
                    res = 0;
                }

                res = max(res-dungeon[y][x],1);
                memo[y][x] = res;
            }
        }
        
        for (auto y : memo){
            for (auto x:y){
                cout<<x<<' ';
            }
            cout<<endl;
        }


        return memo[0][0];

        

    }
};
// @lc code=end

