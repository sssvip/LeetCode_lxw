// File: num145.cpp
// Author: lxw
// Date: 2015-07-28

/*
Num num145: Binary Tree Postorder Traversal
Source: https://leetcode.com/problems/binary-tree-postorder-traversal/

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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

//Recursive
class Solution {
private:
    vector<int> postOrderVec;
    void postOrder(TreeNode * root){
        if(root == NULL)
            return;
        postOrder(root->left);
        postOrder(root->right);
        this->postOrderVec.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return this->postOrderVec;
    }
};

//Iterative
struct Tuple{
    Tuple(TreeNode * tn, int value):node(tn), tag(value){}
    TreeNode * node;
    int tag;
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        stack<Tuple> s;
        if(root == NULL)
            return postOrder;
        s.push(Tuple(root, 0));
        while(!s.empty()){
            Tuple & t = s.top();
            s.pop();
            if(t.tag == 0){ //first time pop out.
                //入栈的顺序非常重要: 先入当前节点, 然后入右节点, 最后入左节点
                s.push(Tuple(t.node, 1));
                if(t.node->right)
                    s.push(Tuple(t.node->right, 0));
                if(t.node->left)
                    s.push(Tuple(t.node->left, 0));
            }
            else{   //second time pop out.
                postOrder.push_back(t.node->val);
            }
        }
        return postOrder;
    }
};
