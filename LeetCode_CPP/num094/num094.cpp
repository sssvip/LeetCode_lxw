// File: num094.cpp
// Author: lxw
// Date: 2015-07-28

/*
Num 094: Binary Tree Inorder Traversal
Source: https://leetcode.com/problems/binary-tree-inorder-traversal/

Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

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
//recursive
class Solution {
private:
    vector<int> inOrderVec;
    void inOrder(TreeNode * root){
        if(root == NULL)
            return;
        inOrder(root->left);
        this->inOrderVec.push_back(root->val);
        inOrder(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return this->inOrderVec;
    }
};

//iterative
