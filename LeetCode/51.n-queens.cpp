/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
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

typedef vector<string> board;


class Solution {
public:

    vector<board> dp(board b,int level){
        int yMax = b.size();
        int xMax = b[0].size();
        if (yMax == level){
            return {b};
        }

        //place diagonals
        //place verticals
        //place horizontals

        auto insertQueen = [yMax,xMax](board &curr, int y,int x) -> void{
    
            //horizontal
            for (int xc = 0;xc<xMax;xc++){
                curr[y][xc] = 'X'; 
            }
            //vertical
            for (int yc = 0;yc<yMax;yc++){
                curr[yc][x] = 'X'; 
            }


            //diagonals
            for (int xc = 0;xc<xMax;xc++){
                for (int yc = 0;yc<yMax;yc++){
                    int yinv = yMax-1 -yc;
                    //positive diagonal
                    if (xc + yc == x + y){
                        curr[yc][xc] = 'X';
                    }
                    if (xc + yinv == x + yMax - y - 1){
                        curr[yc][xc] = 'X';
                    }
                    

                }
            }

            curr[y][x] = 'Q';
        };

        vector<board> validStates;
        for (int i =0;i < xMax;i++){
            if (b[level][i] == '.'){
                auto newBoard = b;
                insertQueen (newBoard,level,i);
                for (auto successBoard : dp(newBoard,level+1)){
                    validStates.push_back(successBoard);
                }   
            }
        }



        return validStates;
        

        


    }
    vector<board> solveNQueens(int n) {

        auto results=  dp(board(n,string(n,'.')),0);

        auto reworkBoard = [](board & b)->void{
            for(auto& row : b){
                for (auto& col:row){
                    if (col == 'X'){
                        col = '.';
                    }
                }
            }
        };

        for (auto& r:results){
            reworkBoard(r);
        }

        return results;
        

        
    }
};
// @lc code=end

