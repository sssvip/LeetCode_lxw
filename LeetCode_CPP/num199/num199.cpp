// File: num199.cpp
// Author: lxw
// Date: 2015-10-31

/*
Num num199: Binary Tree Right Side View
Source: https://leetcode.com/problems/binary-tree-right-side-view/

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> retArr;
        if(root == NULL)
            return retArr;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);   //level flag
        TreeNode * node;
        int last;
        while(1){
            if(q.empty())
                break;
            node = q.front();
            q.pop();
            if(node == NULL){   //level flag
                retArr.push_back(last);
                if(q.empty())
                    break;
                q.push(NULL);
            }
            else{
                last = node->val;
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
            }
        }
        return retArr;
    }
};