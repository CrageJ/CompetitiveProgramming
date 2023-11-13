/*
 * @lc app=leetcode id=2785 lang=cpp
 *
 * [2785] Sort Vowels in a String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

bool isVowel(char c){
    if (c <= 'z'){
        if (c == 'a' || c=='e' || c=='i'||c=='o'||c=='u'){
            return true;
        }
        
    }
    if (c <= 'Z'){
        if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            return true;
        }
    }
    return false;
}


    string sortVowels(string s) {

        vector<int> chars;
        //vector<bool> isVowelList;
        for (auto c:s){
            if (isVowel(c)){
                //cout <<c<<(int)c<<' ';
                chars.push_back(c);
            }
        }

        sort(chars.begin(),chars.end());

        int vowelIndex = 0;
        for (int i = 0;i< s.size();i++){
            if (isVowel(s[i])){
                s[i] = chars[vowelIndex];
                vowelIndex++;
            }
            
        }

        return s;


    }
};
// @lc code=end

