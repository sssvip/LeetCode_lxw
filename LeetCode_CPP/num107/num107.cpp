// File: num107.cpp
// Author: lxw
// Date: 2015-07-09

/*
Num num107: Binary Tree Level Order Traversal II
Source: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    /* OK
    void reverse(vector<vector<int> > & vvi){
        int length = vvi.size();
        int mid = length >> 1;
        for(int i = 0; i < mid; ++i){
            //Both of the following 2 methods are OK.
            //vvi[i].swap(vvi[length-1-i]);
            vector<int> temp = vvi[i];
            vvi[i] = vvi[length-1-i];
            vvi[length-1-i] = temp;
        }
    }*/
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode *> qtn;
        vector<vector<int> > vvi;
        if(root == NULL)
            return vvi;
        qtn.push(root);
        int count = 1;
        TreeNode * node;
        while(count > 0){
            int i = 0;
            int tempCount = 0;
            vector<int> vi(0);
            while(i < count){
                if(qtn.empty()){
                    count = 0;
                    break;
                }
                node = qtn.front();
                vi.push_back(node->val);
                qtn.pop();
                if(node->left != NULL){
                    qtn.push(node->left);
                    ++tempCount;
                }
                if(node->right != NULL){
                    qtn.push(node->right);
                    ++tempCount;
                }
                ++i;
            }
            vvi.push_back(vi);
            count = tempCount;
        }
        reverse(vvi.begin(), vvi.end());
        //reverse(vvi);
        return vvi;
    }
};