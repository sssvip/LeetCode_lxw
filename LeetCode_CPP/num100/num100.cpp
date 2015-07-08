// File: num100.cpp
// Author: lxw
// Date: 2015-07-08

/*
Num num100: Same Tree
Source: https://leetcode.com/problems/same-tree/

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
public:
    bool isSameTreeRecursive(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        if(p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    //DFS
    bool isSameTreeIterative(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
            return true;
        if(p == NULL || q == NULL)
            return false;
        stack<TreeNode *> treeStack1;
        stack<TreeNode *> treeStack2;
        if(p->val == q->val){
            treeStack1.push(p);
            treeStack2.push(q);
        }
        else{
            return false;
        }
        //size is identical.
        //while(!treeStack1.empty() && !treeStack2.empty())
        while(!treeStack1.empty()){
            p = treeStack1.top();
            q = treeStack2.top();
            treeStack1.pop();
            treeStack2.pop();
            if(p->right != NULL && q->right != NULL){
                if(p->right->val == q->right->val){
                    treeStack1.push(p->right);
                    treeStack2.push(q->right);
                }
                else{
                    return false;
                }
            }
            else if(p->right != NULL || q->right != NULL){
                return false;
            }
            
            if(p->left != NULL && q->left != NULL){
                if(p->left->val == q->left->val){
                    treeStack1.push(p->left);
                    treeStack2.push(q->left);
                }
                else{
                    return false;
                }
            }
            else if(p->left != NULL || q->left != NULL){
                return false;
            }
        }
        return true;
    }
};