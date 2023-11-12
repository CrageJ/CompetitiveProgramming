/*
 * @lc app=leetcode id=1492 lang=cpp
 *
 * [1492] The kth Factor of n
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    set<int> s;
    
    int kthFactor(int n, int k) {
        if (k == 1){
            return 1;
        }

        set<int> S;
        S.insert(1);
    
        for (int factor = 2;factor<=n;factor++){
            bool factorFailed = false;
            if (S.count(factor)> 0){
                factorFailed = true;
            }   
            //vector<int> factorList;
            int factorIteration = 0;
            while (!factorFailed){
                factorIteration++;
                int factorResult = factor*factorIteration;
                if (factorResult > n){
                    factorFailed = true;
                    break;
                }
                if (factorResult == n){
                    //factorList.push_back(factorResult);
                    break;
                }
                if (factorResult < n){
                    //factorList.push_back(factorResult);
                }
            }
            if (!factorFailed){
                S.insert(factor);
            }
        }
    vector<int> v(S.begin(),S.end());


    if (v.size() < k){
        return -1;
    }
    sort(v.begin(),v.end());
    for (auto item:v){
        std::cout<< item<<' ';
    }
    return v[k-1];

    }
};
// @lc code=end

