// File: num145.cpp
// Author: lxw
// Date: 2015-07-28

/*
Num num145: Binary Tree Postorder Traversal
Source: https://leetcode.com/problems/binary-tree-postorder-traversal/

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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

//Recursive
class Solution {
private:
    vector<int> postOrderVec;
    void postOrder(TreeNode * root){
        if(root == NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        this->postOrderVec.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return this->postOrderVec;
    }
};

//Iterative