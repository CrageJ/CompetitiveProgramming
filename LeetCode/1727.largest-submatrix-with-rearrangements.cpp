/*
 * @lc app=leetcode id=1727 lang=cpp
 *
 * [1727] Largest Submatrix With Rearrangements
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
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(); //y
        int n = matrix[0].size(); //x

        //cout<<m<<n;

        vector<vector<int>> rotated;
        for(int x = 0;x<n;x++){
            vector<int> r;
            for(int y = 0;y<m;y++){
                r.push_back(matrix[y][x]);
            }
            //cout<<r.size();

            rotated.push_back(r);
        }

        sort(rotated.begin(),rotated.end(),[](const vector<int>& lhs,const vector<int>& rhs){
            for (int i = 0;i< lhs.size();i++){
                if (lhs[i] != rhs[i]){
                    return lhs[i]>rhs[i];
                }
            }
            return true; 
        });
        for (auto a : rotated){
            cout<<endl;
            for (auto b:a){
                cout<<b<<' ';
            }
        }

        int ret = 0;
        for (int i = 0;i< rotated.size();i++){
            for (int index = 0;index < rotated[0].size() && rotated[i][index] != 0;i++){
                ret = max(ret, (index+1)*(i+1));
            }
        }

        return ret;

        
    };
};
// @lc code=end

