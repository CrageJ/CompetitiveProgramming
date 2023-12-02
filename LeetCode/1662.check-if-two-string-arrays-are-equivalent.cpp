/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */


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
// @lc code=start
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
       // sort(word1.begin(),word1.end());
       // sort(word2.begin(),word2.end());

        string w1;
        for (auto word:word1){
            w1 += word;
        }

        string w2;
        for (auto word:word2){
            w2 += word;
        }


        return w1 == w2;
    }
};
// @lc code=end

