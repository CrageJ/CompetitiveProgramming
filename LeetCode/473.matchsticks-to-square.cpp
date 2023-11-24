/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
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

//bitarr represents the matches used so far, in bitform
int mask (int idx, int bitarr){
    int bit = 1<<idx;
    return bitarr | bit;
}

vector<int> matches;

unordered_map<pair<int,int>,bool,PairHash<int>> memo;

    bool dp (int sideLen, int bitarr){
        pair<int,int> args = {sideLen,bitarr};
        if (memo.count(args) > 0){
            return memo[args];
        }

        //iterate through bit array, determine which side am on;
        int currSide = 0;
        //perimiter
        int targetPerimiter = sideLen*4;
        int currPerimiter = 0;

        //calculating state of iteration
        for (int i = 0;i< matches.size();i++){
            int currElement = mask(i,0);
            if (currElement & bitarr){
                currPerimiter += matches[i];
            }
        }

        currSide = currPerimiter /sideLen;
        int currSideLen = currPerimiter - (currSide*sideLen);

        if (currPerimiter == targetPerimiter){
            memo[args] = true;
            return true;
        }

        if (currPerimiter > targetPerimiter){
            memo[args] = false;
            return false;
        }

        for (int i = 0;i< matches.size();i++){
            int currElement = mask(i,0);

            //if element hasn't been selected yet and choosing it wouldn't overextend 
            //since elements are ordered, choosing a too large element means subsequent elements are also too large
            if (matches[i] + currSideLen > sideLen){
                break;
            }
            // if bitarr does not have  element
            if (!(currElement & bitarr)){
                if (dp(sideLen, mask(i,bitarr))){
                    memo[args] = true;
                    return true;
                }
                //if this is the first side, we can also 
            }
        }

        memo[args] = false;
        return false;

    }

    set<ll> getEverySubsequenceSum(vector<ll> v){
        if (v.empty() ){
            return {0};
        }

        set<ll> sset;
        ll firstItem = v[0];

        vector<ll> vsub(v.begin()+1,v.end());

        for (auto item : getEverySubsequenceSum(vsub)){
            sset.insert(item);
            sset.insert(item + firstItem);
        }

        return sset;
    }



    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(),matchsticks.end());
        // all possible length combinations
        vector<ll> matches;

        for (auto m:matchsticks){
            matches.push_back((ll)m);
        }

        //for (ll sideLen = 1; sideLen <= 100000000;sideLen*=2)
        for (auto l: getEverySubsequenceSum(matches)){
            if (l < 0 && l <= 100000000){
                for (int i = 0;i<16;i++){
                    if (dp(l,mask(i,0))){
                        return true;
                    }
                }
            }
        }

        return false;

    }
};
// @lc code=end

