/*
 * @lc app=leetcode id=1424 lang=cpp
 *
 * [1424] Diagonal Traverse II
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








//<index, order>,value


class Solution {
public:


    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {

        vector<vector<int>> sol;

        for (int y = 0;y< nums.size();y++){
            for (int x = 0;x<nums[y].size();x++){
                vector<int> curr = {x+y,y,nums[y][x]};
                sol.push_back(curr);
            }
        }

        sort(sol.begin(),sol.end(),[](const auto &lhs , const auto & rhs){
            if (lhs[0]==rhs[0]){
                return lhs[1] > rhs[1]; 
            }
            return lhs[0] < rhs[0];
        });


        vector<int> ret;

        for (auto i:sol){
            ret.push_back(i[2]);
        }


        return ret;

    };


};
// @lc code=end


/*
class Solution {
public:
vector<vector<int>> nums;
int maxY = 1;
int maxX = 1;
    int getNum(int y, int x){

        if (y >= maxY ||nums[y].size() <= x){
            return 0;
        }
        return nums[y][x];

    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        this->nums = nums;

        maxX=1; // wide
        maxY=nums.size(); // deep
        
        for (vector<int> a : nums){

            int si = a.size();
            maxX = max(si,maxX);
        }

        vector<int> v;

        for (int y = 0;y< maxY+maxX -1;y++){
            for (int x = max(0,y-maxY-1);x<=y;x++){
                //cout << x<<' '<<y;

                auto a = getNum(y-x,x);
                
                if (a > 0){
                    v.push_back(a);
                }

            }
        }

        return v;

    }
};

*/

