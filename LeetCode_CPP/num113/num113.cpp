// File: num113.cpp
// Author: lxw
// Date: 2015-07-09

/*
Num num113: Path Sum II
Source: https://leetcode.com/problems/path-sum-ii/

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
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
    vector<vector<int> > vvi;
    void pathSum(TreeNode * root, int sum, vector<int> & vi){ //root != NULL
        if(root->left == NULL && root->right == NULL){
            if(sum == root->val){
                vi.push_back(sum);
                this->vvi.push_back(vi);
                vi.pop_back(); //here is essential, Otherwise "Output Limit Exceeded".
            }
            return;
        }
        sum -= root->val;
        vi.push_back(root->val);
        if(root->left != NULL){
            pathSum(root->left, sum, vi);
        }
        if(root->right != NULL){
            pathSum(root->right, sum, vi);
        }
        vi.pop_back();  //here is essential, Otherwise "Output Limit Exceeded".
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return this->vvi;
        vector<int> vi;
        pathSum(root, sum, vi);
        return this->vvi;
    }
};