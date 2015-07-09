// File: num117.cpp
// Author: lxw
// Date: 2015-07-09

/*
Num num117: Populating Next Right Pointers in Each Node II 
Source: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
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
        int tempCount = 0;
        TreeLinkNode * node1;
        TreeLinkNode * node2;
        while(1){
            tempCount = 0;
        	node1 = nodeQueue.front();
        	nodeQueue.pop();
        	if(node1->left != NULL){
        		nodeQueue.push(node1->left);
        		++tempCount;
        	}
        	if(node1->right != NULL){
        		nodeQueue.push(node1->right);
        		++tempCount;
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
        			++tempCount;
        		}
        		if(node2->right != NULL){
        			nodeQueue.push(node2->right);
        			++tempCount;
        		}
        	}
        	node1->next = NULL;
        	if(tempCount == 0)//if(nodeQueue.empty())   //
        		break;
        	count = tempCount;
        }
    }
};