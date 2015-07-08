// File: num102.cpp
// Author: lxw
// Date: 2015-07-08

/*
Num num102: Binary Tree Level Order Traversal 
Source: https://leetcode.com/problems/binary-tree-level-order-traversal/

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.


OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
    vector<vector<int>> levelOrder(TreeNode* root) {
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
        return vvi;
    }
};