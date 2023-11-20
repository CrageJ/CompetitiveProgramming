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


/*
 * @lc app=leetcode id=2391 lang=cpp
 *
 * [2391] Minimum Amount of Time to Collect Garbage
 */

// @lc code=start
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int mDistance = 0;
        int pDistance = 0;
        int gDistance = 0;

        int minutes = 0;
        
        for (int i = 0;i< garbage.size();i++){
            int travelTime;
            if (i < garbage.size() -1){
                travelTime = travel[i];
            }
            else{
                travelTime = 0;
            }

            int mCount = 0;
            int pCount = 0;
            int gCount = 0;
            for (auto garbageType : garbage[i]){
                minutes++;
                switch(garbageType){
                    case 'M':
                    minutes += mDistance;
                    mDistance= 0;
                    break;
                    case 'P':
                    minutes += pDistance;
                    pDistance= 0;
                    break;
                    case 'G':
                    minutes += gDistance;
                    gDistance= 0;
                    break;
                }
            }

            mDistance += travelTime;
            gDistance += travelTime;
            pDistance += travelTime;
        }

        return minutes;
        
    }
};
// @lc code=end

