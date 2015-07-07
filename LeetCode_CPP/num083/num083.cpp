// File: num083.cpp
// Author: lxw
// Date: 2015-07-07

/*
Num 083: Remove Duplicates from Sorted List
Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode * newHead = head;
        ListNode * current;
        while(1){
            current = head;
            while(head->next != NULL && head->next->val == head->val){
                head = head->next;
            }
            if(head->next == NULL){
                current->next = NULL;
                break;
            }
            else{
                head = head->next;
                current->next = head;
            }
        }
        return newHead;
    }
};