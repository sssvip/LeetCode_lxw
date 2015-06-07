// File: num024.cpp
// Author: lxw
// Date: 2015-06-07

/*
Num 024: Swap Nodes in Pairs
Source: https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode * current = new ListNode(0);
        current->next = head;
        head = current;
        ListNode *p1 = NULL;
        ListNode *p2 = NULL;
        while(1){
            p2 == NULL;
            p1 = current->next;
            if(p1 == NULL){
                break;
            }
            p2 = p1->next;
            if(p2 == NULL){
                break;
            }
            current->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            current = p1;
        }
        return head->next;
    }
};
