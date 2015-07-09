// File: num111.cpp
// Author: lxw
// Date: 2015-07-09

/*
Num num111: Minimum Depth of Binary Tree
Source: https://leetcode.com/problems/minimum-depth-of-binary-tree/

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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
    int minDepth1(TreeNode * root){   //root != NULL
        if(root->left == NULL && root->right == NULL)
            return 1;
        if(root->left == NULL)  //root->right != NULL
            return minDepth1(root->right)+1;
        if(root->right == NULL)  //root->left != NULL
            return minDepth1(root->left)+1;
        return min(minDepth1(root->left), minDepth1(root->right)) + 1;
    }
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return minDepth1(root);
    }
};