// File: num236.cpp
// Author: lxw
// Date: 2015-07-22

/*
Num num236: Lowest Common Ancestor of a Binary Tree
Source: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/

//如果是普通二叉树, 而不是BST.  则应该遍历节点, 先找到p,q. 同时记录下从root到该几点的路径.
//之后比较路径,最后一个相同的节点便是LCA.

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
        if(root == NULL || p == NULL || q == NULL)
            return NULL;
        vector<TreeNode *> lPath;
        vector<TreeNode *> rPath;
        lPath.push_back(root);
        rPath.push_back(root);
        getPath(root, p, lPath);
        getPath(root, q, rPath);
        int length = min(lPath.size(), rPath.size());
        int i = 0;
        TreeNode * common = NULL;
        while(i < length){
            if(lPath[i] == rPath[i])
                common = lPath[i];
            else
                break;
            ++i;
        }
        return common;
    }
    //NOTE: if "vector<TreeNode*> path", we will get the "Memory Limit Exceeded".
    bool getPath(TreeNode * current, TreeNode * node, vector<TreeNode*>& path){
        if(current == node){
            return true;
        }
        if(current->left != NULL){
            path.push_back(current->left);
            if(getPath(current->left, node, path))
                return true;
            path.pop_back();
        }
        if(current->right != NULL){
            path.push_back(current->right);
            if(getPath(current->right, node, path))
                return true;
            path.pop_back();
        }
        return false;
    }
};