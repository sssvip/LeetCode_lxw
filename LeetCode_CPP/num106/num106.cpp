// File: num106.cpp
// Author: lxw
// Date: 2015-07-08

/*
Num num106: Construct Binary Tree from Inorder and Postorder Traversal
Source: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Given inorder and postorder traversal of a tree, construct the binary tree.

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
class Solution {
private:
    TreeNode * buildTree(vector<int>& inorder, int start1, int end1, vector<int>& postorder, int start2, int end2) {
        if(start1 == end1)
            return new TreeNode(inorder[start1]);
        if(start1 > end1)
            return NULL;
        int i = start1;
        for(; i <= end1; ++i){
            if(inorder[i] == postorder[end2])
                break;
        }
        TreeNode * node = new TreeNode(postorder[end2]);
        node->left = buildTree(inorder, start1, i-1, postorder, start2, start2-start1+i-1);
        node->right = buildTree(inorder, i+1, end1, postorder, start2-start1+i, end2-1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int end = inorder.size() - 1;
        return buildTree(inorder, 0, end, postorder, 0, end);
    }
};