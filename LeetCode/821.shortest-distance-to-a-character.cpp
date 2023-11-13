/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {

        vector<int>answer(s.size(),INT_MAX);
        
        for (int i = 0;i< s.size();i++){
            if (s[i] == c){
                answer[i] = 0;
            }
        }



        //forwards
        int lastSeen = -1;
        for (int i = 0;i<s.size();i++){

            if (answer[i]== 0){
                lastSeen = i;
                continue;
            }
            if (lastSeen == -1 ){
                continue;
            }
          
            answer[i] = i-lastSeen;
        }


        lastSeen = -1;

        for (int i = s.size()-1;i>=0;i--){
            
            if(answer[i]== 0){
                lastSeen = i;
                continue;
            }
            
            if (lastSeen == -1 ){
                continue;
            }
            
            answer[i] = min(lastSeen-i,answer[i]);
        }


        return answer;
        
    }
};
// @lc code=end

