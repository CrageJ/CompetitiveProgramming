/*
 * @lc app=leetcode id=794 lang=cpp
 *
 * [794] Valid Tic-Tac-Toe State
 */

// @lc code=start


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


//0 = x, 1 = o, 2 = empty
long isPlaced(long boardstate,long location){
    if (((boardstate >> location ) & 0b1)>0){
        return 0;
    }  
    if (((boardstate >> (location + 9) )& 0b1)> 0){
        return 1;
    }
    return 2;
}

//type == 0,x / 1,O
long place(long boardstate,long location,long type){
    long placeLocation = 1<<(location+(type*9));
    boardstate |=placeLocation;
    return boardstate;
}

bool isWon(long boardstate){

    for (long offset = 0;offset<3;offset++){
        long Oplacelocation = 0b111<<(offset*3);
        long Xplacelocation = Oplacelocation<<9;
        if ((boardstate & Oplacelocation)==Oplacelocation ||(boardstate & Xplacelocation)==Xplacelocation ){
            return true;
        }
    }

    for (long offset = 0;offset<3;offset++){
        long Oplacelocation = 0b1001001<<(offset);
        long Xplacelocation = Oplacelocation<<9;
        if ((boardstate & Oplacelocation)==Oplacelocation ||(boardstate & Xplacelocation)==Xplacelocation ){
            return true;
        }
    }

    long Odiagonal=0b100010001;
    long Xdiagonal=Odiagonal <<9;
    if ((boardstate & Odiagonal)==Odiagonal ||(boardstate & Xdiagonal)==Xdiagonal ){
        return true;
    }


    Odiagonal=0b0010101;
    Xdiagonal=Odiagonal <<9;

    if ((boardstate & Odiagonal)==Odiagonal ||(boardstate & Xdiagonal)==Xdiagonal ){
        return true;
    }

    return false;


    
}

//true = valid, false = invalid

long finalState;
long finalTurnCount;
    bool dp (long boardState, long turnCount){

        if ((boardState == finalState) && (turnCount == finalTurnCount)){
            return true;
        }

        if (isWon(boardState)){
            return false;
        }
        if (turnCount >=finalTurnCount){
            return false;
        }

        bool isWinner = false;
        long playerType = turnCount%2; // represented by X
        long notPlayerType = 1-playerType;
        for (long i = 0; i<9 && !isWinner;i++){
            if (isPlaced(boardState,i) == 2){
                isWinner |= dp (place(boardState,i,playerType),turnCount+1);
            }
            
            
        }
        return isWinner;
    }
    

    bool validTicTacToe(vector<string>& board) {       

        long boardState = 0;
        long turnCount = 0;
        long xCount = 0;
        long oCount = 0;
        for (long i = 0;i<3;i++){
            for (long j = 0;j<3;j++){
                long pos = i*3 + j;
                long position = 1<<pos;
                if (board[i][j] == 'X'){
                    xCount++;
                    turnCount++;
                    boardState |= position;
                }
                if (board[i][j] == 'O'){
                    oCount++;
                    turnCount++;
                    boardState |= (position <<9);
                }
            }
        }

        finalTurnCount = turnCount;
        finalState = boardState;
        long b = boardState;
        while (b != 0){
           //cout<<(b&1);

            b/=2;
        }

        //if had the same amount o turns or if x has had one more turn than o
        if (!((xCount == oCount)||(xCount-1 ==  oCount)) ){
            return false;
        }

        
        
        return dp(0,0);
    }
};
// @lc code=end

