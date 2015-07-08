// File: num101.cpp
// Author: lxw
// Date: 2015-07-08

/*
Num num101: Symmetric Tree 
Source: https://leetcode.com/problems/symmetric-tree/

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

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
 
//n nodes:
//Time Cost: O(n); Space Cost: O(n)
class Solution {
private:
    bool isLayerSymmetric(vector<TreeNode *> & vt, int start, int end){
        if(start > end){
            return false;
        }
        if(start == end){
            return true;
        }
        while(start < end){
            if(vt[start] == NULL and vt[end] == NULL){
                ++start;
                --end;
                continue;
            }
            if(vt[start] == NULL || vt[end] == NULL){
                return false;
            }
            if(vt[start]->val == vt[end]->val){
                ++start;
                --end;
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        vector<TreeNode *> vt;
        vt.push_back(root);
        int i = 0;
        int length = 1;
        while(i < length){
            if(isLayerSymmetric(vt, i, length-1)){
                while(i < length){
                    if(vt[i] != NULL){
                        vt.push_back(vt[i]->left);
                        vt.push_back(vt[i]->right);
                    }
                    ++i;
                }
            }
            else{
                return false;
            }
            length = vt.size();
        }
        return true;
    }
};