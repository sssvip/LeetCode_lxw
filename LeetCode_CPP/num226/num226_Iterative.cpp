// File: num226.cpp
// Author: lxw
// Date: 2015-06-13

/*
Num 226: Invert Binary Tree
Source: https://leetcode.com/problems/invert-binary-tree/

Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9
to
     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:
Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        stack<TreeNode *> nodeStack;
        nodeStack.push(root);
        while(!nodeStack.empty()){
            TreeNode * current = nodeStack.top();
            nodeStack.pop();
            TreeNode * temp = current->left;
            current->left = current->right;
            current->right = temp;
            if(current->left != NULL){
                nodeStack.push(current->left);
            }
            if(current->right != NULL){
                nodeStack.push(current->right);
            }
        }
        return root;
    }
};
