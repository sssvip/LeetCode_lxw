// File: num141.cpp
// Author: lxw
// Date: 2015-09-04

/*
Num num141: Linked List Cycle
Source: https://leetcode.com/problems/linked-list-cycle/

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode * p1 = head;
        ListNode * p2 = head;
        while(1){
            if(p1 == NULL || p2 == NULL)
                break;
            p1 = p1->next;
            p2 = p2->next;
            if(p2 == NULL)
                break;
            else
                p2 = p2->next;
            if(p1 == p2)
                return true;
        }
        return false;
    }
};