// File: num105_optimize.cpp
// Author: lxw
// Date: 2015-07-08

/*
Num 105: Construct Binary Tree from Preorder and Inorder Traversal 
Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
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

//不如num105.cpp好理解
//optimize: 少传一个参数
//时间上并没有明显的优化
class Solution {
private:
    TreeNode* buildTree(vector<int>& preorder, int start1, vector<int>& inorder, int start2, int length) {
        if(length == 1){
            return new TreeNode(preorder[start1]);
        }
        if(length == 0){
            return NULL;
        }
        int i = 0;
        for(; i < length; ++i){
            if(inorder[start2+i] == preorder[start1])
                break;
        }
        TreeNode * node = new TreeNode(preorder[start1]);
        node->left = buildTree(preorder, start1+1, inorder, start2, i);
        node->right = buildTree(preorder, start1+i+1, inorder, start2+i+1, length-i-1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, inorder, 0, preorder.size());
    }
};