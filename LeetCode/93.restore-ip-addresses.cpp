/*
 * @lc app=leetcode id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    bool isValidInt(string s){
        if (s == "0"){
            return true;
        }
        if (s[0] == '0'){
            return false;
        }
        int i = stoi(s);
        if (i > 255){
            return false;
        }
        
        return true;
        
    }
    vector<string> dp (string s, int integerCount){
        
        
        if (integerCount > 4){
            return {};
        }
        if (integerCount == 4 && s.length() == 0){
            return {""};
        }
        if (s.length() == 0){
            return {};
        }

        int strlen = s.size();

        vector<string> solutions = {};


        for (int sublen = 1;sublen <=min(3,strlen);sublen++){
                string len1 = s.substr(0,sublen);
                
                if (isValidInt(len1)){
                    auto subsols = dp (s.substr(sublen,strlen-sublen),integerCount+1);
                    for (auto subsol : subsols ){
                        solutions.push_back(len1 +"."+subsol);
                    }
                }
        }

        return solutions;
        
    }
    vector<string> restoreIpAddresses(string s) {
        auto result = dp (s,0);
        set<string> S;
        for (auto r:result){
            S.insert(r);
        }
        result = {};
        for (auto item: S){
            result.push_back(item.substr(0,item.length()-1));
        }
        return result;
    }
};
// @lc code=end

