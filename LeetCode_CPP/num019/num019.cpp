// File: num019.cpp
// Author: lxw
// Date: 2015-06-01

/*
Num 019: Remove Nth Node From End of List
Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Remove Nth Node From End of List 

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass.
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
    //OK
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        ListNode * node = head;
        int length = 0;
        while(node != NULL){
            node = node->next;
            ++length;
        }
        if(length < n){
            return head;
        }
        else{
            int target = length - n;
            int i = 0;
            node = head;
            if(target == 0){
                head = head->next;
            }
            else{
                ListNode * prev = head;
                while(i < target){
                    prev = node;
                    node = node->next;
                    ++i;
                }
                prev->next = node->next;
            }
            delete node;
        }
        return head;
    }

    //OK
    ListNode* removeNthFromEnd1(ListNode* head, int n){
        if(head == NULL)
            return head;
        ListNode * node = head;
        for(int i = 0; i < n && node != NULL; ++i){
            node = node->next;
        }
        ListNode * node1 = head;
        if(node == NULL){
            head = head->next;
            node = node1;
        }
        else{
            while(node->next != NULL){
                node = node->next;
                node1 = node1->next;
            }
            node = node1->next;
            node1->next = node1->next->next;
        }
        delete node;
        return head;
    }
};
