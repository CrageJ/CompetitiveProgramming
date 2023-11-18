/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string findDifferentBinaryString(vector<string>& nums){
        string ans;
        for (int i =0;i<nums.size();i++){
            if (nums[i][i] == '0'){
                ans += '1';
            }
            else{
                ans += '0';
            }
            
        }

        return ans;
    }


};



// @lc code=end
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string findDifferentBinaryString(vector<string>& nums) {
        
        set<int> sset;

        for (string  n : nums){
            int num = 0;
            for (char c : n){
                num = num * 2 + (c-'0');
            }
            sset.insert(num);
        }

        for (long i = 0;i<( ((long)1)<<nums.size());i++){
            if (sset.count(i)==0){
       
                string result;
                while (i > 0){
                    if (i&0b1){
                        //cout <<'1';
                        result += '1';
                    }
                    else{
                        //cout <<'0';
                        result += '0';
                    }
                    i/=2;
                }
                //left pad answer
                reverse(result.begin(),result.end());

                while (result.size() < nums.size()){
                    result = '0'+result;
                }
                return result;
            }
        }
        return "";



        





    }
};
*/

