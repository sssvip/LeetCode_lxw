// File: num109.cpp
// Author: lxw
// Date: 2015-07-09

/*
Num num109: Convert Sorted List to Binary Search Tree
Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode * sortedListToBST(ListNode * head, int length){
        if(length == 0)
            return NULL;
        if(length == 1)
            return new TreeNode(head->val);
        int mid = length >> 1;
        ListNode * current = head;
        for(int i = 0; i < mid; ++i){
            current = current->next;
        }
        TreeNode * node = new TreeNode(current->val);
        node->left = sortedListToBST(head, mid);
        node->right = sortedListToBST(current->next, length-1-mid);
        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int i = 0;
        ListNode * current = head;
        while(current){
            ++i;
            current = current->next;
        }
        return sortedListToBST(head, i);
    }
};
