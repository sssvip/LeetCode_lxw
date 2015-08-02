// File: num129.cpp
// Author: lxw
// Date: 2015-08-02

/*
Num num129: Sum Root to Leaf Numbers
Source: https://leetcode.com/problems/sum-root-to-leaf-numbers/

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sumNums(TreeNode * root, int value){
        int newVal = value + root->val;
        if(root->left == NULL && root->right == NULL)
            return newVal;
        int leftV = 0;
        int rightV = 0;
        if(root->left != NULL)
            leftV = sumNums(root->left, newVal * 10);
        if(root->right != NULL)
            rightV = sumNums(root->right, newVal * 10);
        return leftV + rightV;
    }
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        return sumNums(root, 0);
    }
};