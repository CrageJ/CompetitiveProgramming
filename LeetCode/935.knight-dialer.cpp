/*
 * @lc app=leetcode id=935 lang=cpp
 *
 * [935] Knight Dialer
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

vector<vector<char>> pad {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','*'}
};
//<x,y> n , value


unordered_map<string,ll> memo;

vector<vector<int>> directions = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};

    ll dp (int x, int y, int n){
        if (x < 0 || x >= 3 || y < 0 || y >= 4 || n < 0 || pad[y][x]=='*'){
            return 0;
        }
        if (n == 0){
            return 1;
        }
        string item = to_string(x)+to_string(y)+to_string(n);
        //pair<pair<int,int>,int> item = {{x,y},n};
        if (memo.count(item) != 0){
            return memo[item];
        }

        ll res = 0;
        for (auto& d:directions){
            res += dp(x+d[0],y+d[1],n-1);
            res %= 1000000007;
        }


        memo[item] = res;
        return res;
    }


    int knightDialer(int n) {

        ll res =0;
        n--;
        for (int x = 0;x<3;x++){
            for (int y = 0;y<3;y++){
                res += dp(x,y,n);
                res %= 1000000007;
            }
        }
        res += dp(1,3,n);
        res %= 1000000007;
        return res;
    }
};
// @lc code=end

