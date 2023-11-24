/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
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
    int countBattleships(vector<vector<char>>& board) {
        int ymax = board.size();
        int xmax = board[0].size();
        int BScount = 0;
        for (int y = 0;y<ymax;y++){
            for (int x = 0;x<xmax;x++){
                //if detected, either remove until reach end/left or end/down
                if (board[y][x] == '.'){
                    continue;
                }
                if (x+1 < xmax && board[y][x+1] == 'X'){
                    for (int xp = x+1;xp < xmax && board[y][xp] == 'X';xp++){
                        board[y][xp] = '.';
                    }
                }
                else if (y+1 < ymax && board[y+1][x] == 'X'){
                        for (int yp = y+1;yp < ymax && board[yp][x] == 'X';yp++){
                        board[yp][x] = '.';
                    }

                }

                board[y][x] = '.';

                BScount++;
                
            }
        }

        return BScount;
    }
};
// @lc code=end

