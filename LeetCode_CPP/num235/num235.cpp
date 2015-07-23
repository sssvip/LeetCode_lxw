// File: num235.cpp
// Author: lxw
// Date: 2015-07-22

/*
Num num235: Lowest Common Ancestor of a Binary Search Tree
Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * current = root;
        TreeNode * left = NULL;
        TreeNode * right = NULL;
        while(current){
            if(p->val < q->val){
                left = p;
                right = q;
            }
            else{  //p->val >= q->val
                left = q;
                right = p;
            }
            //left->val <= right->val
            if(left->val == current->val || right->val == current->val)
                return current;
            if(left->val < current->val && right->val > current->val)
                return current;        
            if(right->val < current->val){
                current = current->left;
                continue;
            }
            else if(left->val > current->val){
                current = current->right;
                continue;
            }
        }
        return NULL;
    }
};