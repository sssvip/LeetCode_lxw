// File: num237.cpp
// Author: lxw
// Date: 2015-07-18

/*
Num num237: Delete Node in a Linked List 
Source: https://leetcode.com/problems/delete-node-in-a-linked-list/

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL)
            return;
        ListNode * prev = NULL;
        while(node->next != NULL){
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        delete node;
        prev->next = NULL;
    }
};