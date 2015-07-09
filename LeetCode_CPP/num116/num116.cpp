// File: num116.cpp
// Author: lxw
// Date: 2015-07-09

/*
Num num116: Populating Next Right Pointers in Each Node
Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
          return;
        queue<TreeLinkNode *> nodeQueue;
        nodeQueue.push(root);
        int count = 1;
        int i = 1;
        TreeLinkNode * node1;
        TreeLinkNode * node2;
        while(1){
          node1 = nodeQueue.front();
          nodeQueue.pop();
          if(node1->left != NULL){
            nodeQueue.push(node1->left);
            nodeQueue.push(node1->right);
          }
          i = 1;
          while(i < count){
            node2 = nodeQueue.front();
            nodeQueue.pop();
            node1->next = node2;
            node1 = node1->next;
            ++i;
            if(node2->left != NULL){
              nodeQueue.push(node2->left);
              nodeQueue.push(node2->right);
            }
          }
          node1->next = NULL;
          if(nodeQueue.empty())
            break;
          count <<= 1; //count *= 2; //NOTE: NOT "count << 1;" BUT "count <<= 1;" 
        }
    }
};