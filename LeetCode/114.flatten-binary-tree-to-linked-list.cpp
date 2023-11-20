/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 */

 // Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
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
class Solution {
public:

    TreeNode * traverse(TreeNode* currentNode,TreeNode * insertNode){
        if (currentNode == nullptr){
            return nullptr;
        }


        auto right = currentNode->right;
        auto left = currentNode->left;
        
        auto curr = traverse(left,insertNode);
        if (curr != nullptr){
            insertNode = curr;
        }

        insertNode->right = currentNode;
        insertNode = insertNode->right;
        
        curr = traverse(right,insertNode);
        if (curr != nullptr){
            insertNode = curr;
        }

        return insertNode;
        
        
        
    }
    void flatten(TreeNode* root) {

        auto r = new TreeNode(-1);
        
        traverse(root,r);

        root->right = r->right;

        return;
    }
};
// @lc code=end

