/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 */

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;



class Solution {
public:

    vector<int> traverse(TreeNode * root){
        if (root == nullptr){
            return{};
        }
        if (root->left == nullptr && root->right == nullptr){
            return{root->val};
        }

        vector<int> result;
        auto l = traverse(root->right);
        auto r = traverse(root->left);
        l.insert(l.end(),r.begin(),r.end());
        return l;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        auto r1 = traverse(root1);
        auto r2 = traverse(root2);
        return r1 == r2;
    }
};
// @lc code=end

