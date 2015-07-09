// File: num110.cpp
// Author: lxw
// Date: 2015-07-09

/*
Num num110: Balanced Binary Tree
Source: https://leetcode.com/problems/balanced-binary-tree/

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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
    int getHeight(TreeNode* root){
        if(root == NULL)
            return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        if(isBalanced(root->left) && isBalanced(root->right) && abs(getHeight(root->left) - getHeight(root->right)) < 2){
            return true;
        }
        return false;
    }
};