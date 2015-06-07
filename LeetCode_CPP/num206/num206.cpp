// File: num206.cpp
// Author: lxw
// Date: 2015-06-07

/*
Num 206: Reverse Linked List.
Source: https://leetcode.com/problems/reverse-linked-list/

Reverse a singly linked list.
Hint:
    A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    //Iterative
    ListNode * reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode * p = head;
        ListNode * q = head;
        ListNode * temp = NULL;
        while(q){
            temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        head->next = NULL;
        return p;
    }
    //Recursive
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }
        ListNode * newHead = NULL;
        reverse(head, newHead);
        head->next = NULL;
        return newHead;
    }
    ListNode * reverse(ListNode *head, ListNode *& newHead){
        if(head->next == NULL){
            newHead = head;
            return head;
        }
        ListNode * ln = reverse(head->next, newHead);
        ln->next = head;
        return head;
    }
};
