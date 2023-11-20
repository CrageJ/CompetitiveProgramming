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
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {

    bool isMerged(vector<int> a, vector<int>b){
        if ((a[0] <= b[0] && b[0] <= a[1])||(b[0] <= a[1] && a[1] <= b[1])){
            return true;
        }
        return false;
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            //newly formed interval

        vector<int> insertInterval = newInterval;

        for (int i = 0;i< intervals.size();i++){
            //if new end is beind curr start, skip
            if ( (newInterval[0] > intervals[i][1])){
                continue;
            }
            cout<<i;
            

            //replace r
            int replaceRCount = 0;
            for (int j = i+1;j< intervals.size();j++){
                if (!isMerged(insertInterval,intervals[j])){
                    break;
                }
                cout <<"replaceR";
                insertInterval = {min(intervals[j][0],insertInterval[0]),max(intervals[j][1],insertInterval[1])};
                replaceRCount++;
            }

            for (int j = 0;j<replaceRCount;j++){
                intervals.erase(intervals.begin()+i+1);
            }


            //replace l
            if (isMerged(intervals[i],insertInterval)||isMerged(insertInterval,intervals[i])){
                cout <<"replaceL";
                insertInterval = {min(intervals[i][0],insertInterval[0]),max(intervals[i][1],insertInterval[1])};
                intervals[i] = insertInterval;
            }
            else{
                intervals.insert(intervals.begin()+i,insertInterval);
            }

            return intervals;
        }
        intervals.insert(intervals.end(),insertInterval);
        return intervals;
        
        
    }
};
// @lc code=end

