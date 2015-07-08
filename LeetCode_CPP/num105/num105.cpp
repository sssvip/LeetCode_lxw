// File: num105.cpp
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
class Solution {
private:
    TreeNode* buildTree(vector<int>& preorder, int start1, int end1, vector<int>& inorder, int start2, int end2) {
        if(start1 == end1){ //Actually (start1 == end1) && (start2 == end2)
            return new TreeNode(preorder[start1]);
        }
        if(start1 > end1){ //Actually (start1 < end1) && (start2 < end2)
            return NULL;
        }
        int i = start2;
        for(; i <= end2; ++i){
            if(inorder[i] == preorder[start1])
                break;
        }
        TreeNode * node = new TreeNode(preorder[start1]);
        node->left = buildTree(preorder, start1+1, start1-start2+i, inorder, start2, i-1);
        node->right = buildTree(preorder, start1-start2+i+1, end1, inorder, i+1, end2);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};