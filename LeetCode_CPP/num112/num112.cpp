// File: num112.cpp
// Author: lxw
// Date: 2015-07-09

/*
Num num112: Path Sum 
Source: https://leetcode.com/problems/path-sum/

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum1(TreeNode * root, int sum){ //root != NULL
        if(root->left == NULL && root->right == NULL)
            return sum == root->val;
        sum -= root->val;
        if(root->left != NULL){
            /*
            if(hasPathSum1(root->left, sum)){
                return true;
            }
            is essential.
            return hasPathSum1(root->left, sum);
            is not right. But in 'root->right' case is OK, do you know why?
            */
            if(hasPathSum1(root->left, sum)){
                return true;
            }
        }
        if(root->right != NULL){
            return hasPathSum1(root->right, sum);
        }
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return false;
        return hasPathSum1(root, sum);
    }
};