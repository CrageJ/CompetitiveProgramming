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
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {

        int l = 0, r = citations.size()-1;
        int h = 0;
        while (l <= r){

            int m = ( l + r )/2;
            int mlen = citations.size()-m;
            
            if (mlen <= citations[m]){
                h = max(h,mlen);
                r = m - 1;
            }
            else{
                l = m+1;
            }
        }


        return h;
    }
};
// @lc code=end

