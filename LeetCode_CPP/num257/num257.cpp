// File: num257.cpp
// Author: lxw
// Date: 2015-08-22

/*
Num num257: Binary Tree Paths
Source: https://leetcode.com/problems/binary-tree-paths/

Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
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
    vector<string> vs;
    char * reverse(char * array){
        int length = strlen(array);
        int mid = length / 2;
        char ch;
        for(int i = 0; i < mid; ++i){
            ch = array[i];
            array[i] = array[length-1-i];
            array[length-1-i] = ch;
        }
        return array;
    }
    string int2String(int value){
        long long val = (long long)value;
        char result[11];
        int sign = 0;
        if(value < 0){
            sign = 1;   //negative
            val = -val;
        }
        int i = 0;
        while(val != 0){
            result[i] = val % 10 + '0';
            val = val / 10;
            ++i;
        }
        result[i] = '\0';
        if(sign == 0){  //positive
            return string(reverse(result));
        }
        else{   //negative
            return "-" + string(reverse(result));
        }
    }
    void binaryTreePaths(TreeNode* root, const string & str) {
        if(root->left == NULL && root->right == NULL){
            this->vs.push_back(str);
            return;
        }
        if(root->left != NULL)
            binaryTreePaths(root->left, str + "->" + int2String(root->left->val));
        if(root->right != NULL)
            binaryTreePaths(root->right, str + "->" + int2String(root->right->val));
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root != NULL){
            binaryTreePaths(root, int2String(root->val));
        }
        return this->vs;
    }
};