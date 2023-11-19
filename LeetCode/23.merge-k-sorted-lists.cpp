#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
 
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */





class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * root = new ListNode(INT_MIN);
        priority_queue<int, vector<int>,greater<int>> q;
        for (auto list:lists){
            ListNode *curr=list;
            while (curr != nullptr){
                q.push(curr->val);
                curr = curr->next;
            }
        }
        ListNode * curr=root;
        while (!q.empty()){
            curr->next = new ListNode(q.top());
            q.pop();
            curr = curr->next;
        }

        return root ->next;
         
    }
};
// @lc code=end

