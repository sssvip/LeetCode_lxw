// File: num114.cpp
// Author: lxw
// Date: 2015-07-09

/*
Num num114: Flatten Binary Tree to Linked List
Source: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        TreeNode * head = new TreeNode(0);
        TreeNode * current = head;
        stack<TreeNode *> rNodes;
        while(1){
            while(root){
                current->right = root;
                current->left = NULL;   //Note: essential
                current = current->right;
                if(root->right != NULL)
                    rNodes.push(root->right);
                root = root->left;
            }
            if(rNodes.empty())
                break;
            root = rNodes.top();
            rNodes.pop();
        }
        root = head->right;
        delete head;
    }
};