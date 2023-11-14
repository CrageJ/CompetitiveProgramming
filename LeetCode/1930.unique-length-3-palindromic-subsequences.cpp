/*
 * @lc app=leetcode id=1930 lang=cpp
 *
 * [1930] Unique Length-3 Palindromic Subsequences
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int countPalindromicSubsequence(string s) {
                //has the first character been seen before?
        bool firstCharTrack[26];

        //what second characters have been seen before?
        bool secondCharTrack[26][26];
        bool secondCharStatus[26];

        //what third characters have been seen before?
        bool thirdCharTrack[26];


                // Initialize all arrays to false
        fill(begin(firstCharTrack), end(firstCharTrack), false);
        fill(begin(secondCharStatus), end(secondCharStatus), false);
        fill(begin(thirdCharTrack), end(thirdCharTrack), false);
        for (int i = 0; i < 26; ++i) {
            fill(begin(secondCharTrack[i]), end(secondCharTrack[i]), false);
        }

        int count = 0;

        set<string> sset;
        
        for (char c : s){
            int charIndex = c - 'a';
            if (secondCharStatus[charIndex]){    
               // cout<<"add to third"<<endl;
                for (int j = 0;j<26;j++){
                    if (secondCharTrack[charIndex][j]){
                        string substr = {(char)(j+'a')};
                        substr = c + substr + c;
                        sset.insert(substr);
                        secondCharTrack[charIndex][j]=false;
                    }
                }

                secondCharStatus[charIndex] = false;
            }
            

            //adding c to second
            if (firstCharTrack[charIndex]){
                //cout<<"add to second"<<endl;
               secondCharStatus[charIndex] = true;
            }
            //adding c to * second
            for (int secondIndex = 0;secondIndex < 26;secondIndex ++){
                if (firstCharTrack[secondIndex]){
                  //   cout<<"added "<<c<<" to "<<(char)(secondIndex+'a')<<' '<<endl;
                    secondCharStatus[secondIndex] = true;
                    secondCharTrack[secondIndex][charIndex] = true;
                }
            }
            //adding c to first
             //cout<<"add to first"<<endl;
            firstCharTrack[charIndex] = true;       
        }


        
        
        return sset.size();

    }
};
// @lc code=end

