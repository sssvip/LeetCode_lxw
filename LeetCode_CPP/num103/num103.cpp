// File: num103.cpp
// Author: lxw
// Date: 2015-07-08

/*
Num num103: Binary Tree Zigzag Level Order Traversal
Source: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
	/* OK: but 'std' offers an reverse method(std::reverse(vec.begin(), vec.end())).
    void reverse(vector<int> & vi){
        int length = vi.size();
        int mid = length >> 1;
        int temp = 0;
        for(int i = 0; i < mid; ++i){
            temp = vi[i];
            vi[i] = vi[length-1-i];
            vi[length-1-i] = temp;
        }
    }*/
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
            vector<int> vi;
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
        int level = vvi.size();
        for(int i = 1; i < level; i+=2){
            //reverse(vvi[i]);
            reverse(vvi[i].begin(), vvi[i].end());
        }
        return vvi;
    }
};