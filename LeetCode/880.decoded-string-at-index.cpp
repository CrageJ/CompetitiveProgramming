#include <bits/stdc++.h>
using namespace std;


/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
 */

// @lc code=start
class Solution {
public:
    string decodeAtIndex(string s, int k) {
        int currLen = 0;
        string currString;

        vector<string> strings;
        vector<int> repeats;
        for (char c:s){
            if (c >= 'a' && c <= 'z'){
                currString+= {c};
            }
            //number
            else{
                strings.push_back(currString);
                repeats.push_back(c-'1');
                currString.clear();
            }
        }
        strings.push_back(currString);
        repeats.push_back(1);
        

        for (int end = 1;end<strings.size();end++){
            int endRepeat = repeats[end]; //current repeat
            
            
            for (int l = 0;l<=end;l++){
                endRepeat
            }
                
                
            }
        }


    }
};
// @lc code=end

