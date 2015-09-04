// File: num142.cpp
// Author: lxw
// Date: 2015-09-04

/*
Num num142: Linked List Cycle II
Source: https://leetcode.com/problems/linked-list-cycle-ii/

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

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
    ListNode *detectCycle(ListNode * head) {
        if(head == NULL)
            return NULL;
        //Judge whether cycle exists;
        ListNode * p1 = head;
        ListNode * p2 = head;
        bool cycle = true;
        while(1){
            if(p1 == NULL || p2 == NULL){
                cycle = false;
                break;
            }
            p1 = p1->next;
            p2 = p2->next;
            if(p2 == NULL){
                cycle = false;
                break;
            }
            p2 = p2->next;
            if(p1 == p2){
                cycle = true;
                break;
            }
        }
        if(!cycle){
            return NULL;
        }
        
        //Find the intersection point;
        ListNode * same = p1;
        p1 = head;
        p2 = same->next;
        int length1 = 0;
        int length2 = 0;
        int i = 0;
        while(p1 != same){
            ++length1;
            p1 = p1->next;
        }
        ++length1;
        while(p2 != same){
            ++length2;
            p2 = p2->next;
        }
        ++length2;
        p1 = head;
        p2 = same->next;
        int delta = 0;
        if(length1 > length2){
            delta = length1 - length2;
            for(int i = 0; i < delta; ++i){
                p1 = p1->next;
            }
        }
        else{
            delta = length2 - length1;
            for(int i = 0; i < delta; ++i){
                p2 = p2->next;
            }
        }
        while(p1 != p2){
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};