
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
 * @lc app=leetcode id=1814 lang=cpp
 *
 * [1814] Count Nice Pairs in an Array
 */

// @lc code=start
class Solution {

    vector<int> addNum(vector<int>& a,vector<int>&b){
        int carry = 0;
        vector<int> ret;
        int aptr = a.size()-1;
        int bptr = b.size()-1;

        while (aptr >=0 && bptr >= 0){
            int currInt = a[aptr] + b[bptr] + carry;
            ret.push_back(currInt%10);

            carry = currInt / 10;
            aptr--;
            bptr--; 
        }
        //cout<<"cmp1";

        while (aptr >= 0){
            int currInt = a[aptr] + carry;
            ret.push_back(currInt%10);

            carry = currInt / 10;
            aptr--;
        }
        //cout<<"cmp2";
        while (bptr >= 0){
            int currInt = b[bptr] + carry;
            ret.push_back(currInt%10);

            carry = currInt / 10;
            bptr--;
        }
        //cout<<"cmp3";

        if (carry > 0){
            ret.push_back(carry);
        }

        reverse(ret.begin(),ret.end());
        return ret;
    }


public:
    int countNicePairs(vector<int>& nums) {
        vector<vector<int>> notrev;
        vector<vector<int>> rev;

        sort(nums.begin(),nums.end());
        for (auto n : nums){
            
            int c = n;
            vector<int> curr;
            while (c >9){
                curr.push_back(c%10);
                c/=10;
            }
            curr.push_back(c);
            
            rev.push_back(curr);
            reverse(curr.begin(),curr.end());
            notrev.push_back(curr);
        }

        //cout<<'h';

        //notrev[j]-notrev[i] == rev[j] - rev[i]

        //two pointer
        long long count = 0;
        for (int i = 0;i< rev.size();i++){
            for (int j = i+1;j<rev.size();j++){
                if (addNum(notrev[i],rev[j]) == addNum(notrev[j],rev[i])){
                    count += 1;
                }
            }
        }
        //cout<<'h';

        return count % 1000000007;
        
    }
};
// @lc code=end

