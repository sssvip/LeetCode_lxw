// File: num098.cpp
// Author: lxw
// Date: 2015-08-03

/*
Num 098: Validate Binary Search Tree
Source: https://leetcode.com/problems/validate-binary-search-tree/

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    bool isValidBST(TreeNode * root, long long lowBound, long long upBound){
        if(root == NULL)
            return true;
        if(root->val <= lowBound || root->val >= upBound)
            return false;
        bool leftFlag = true;
        bool rightFlag = true;
        if(root->left != NULL)
            leftFlag = isValidBST(root->left, lowBound, root->val);
        if(root->right != NULL)
            rightFlag = isValidBST(root->right, root->val, upBound);
        return leftFlag && rightFlag;
    }
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, (long long)(INT_MIN) - (long long)(1), (long long)(INT_MAX) + (long long)(1));
    }
};