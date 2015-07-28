// File: num144.cpp
// Author: lxw
// Date: 2015-07-28

/*
Num num144: Binary Tree Preorder Traversal
Source: https://leetcode.com/problems/binary-tree-preorder-traversal/

Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

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
    vector<int> preOrderVec;
    void preOrder(TreeNode* root) {    //CANNOT BE "void preorderTraversal(TreeNode* root)", not overload by return value type.
        if(root == NULL)
            return;
        preOrderVec.push_back(root->val);
        preOrder(root->left);
        preOrder(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preOrder(root);
        return this->preOrderVec;
    }
};

//Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrderVec;
        TreeNode * node = root;
        stack<TreeNode *> s;
        while(1){
            if(node == NULL){
                if(s.empty())
                    break;
                else{
                    node = s.top();
                    s.pop();
                }
            }
            preOrderVec.push_back(node->val);
            //Don't swap the following 2 expressions. Otherwise, node may be NULL when judge "if(node->right)"
            if(node->right)
                s.push(node->right);
            node = node->left;
        }
        return preOrderVec;
    }
};