// File: num160.cpp
// Author: lxw
// Date: 2015-07-17

/*
Num num160: Intersection of Two Linked Lists
Source: https://leetcode.com/problems/intersection-of-two-linked-lists/

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
Special thanks to @stellari for adding this problem and creating all test cases.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * ptrA = headA;
        ListNode * ptrB = headB;
        int length1 = 0;
        int length2 = 0;
        while(ptrA){
            ++length1;
            ptrA = ptrA->next;
        }
        while(ptrB){
            ++length2;
            ptrB = ptrB->next;
        }
        if(length1 == 0 || length2 == 0)
            return NULL;
        ptrA = headA;
        ptrB = headB;
        if(length1 > length2){
            int delta = length1 - length2;
            int i = 0;
            while(i < delta){
                ptrA = ptrA->next;
                ++i;
            }
        }
        if(length1 < length2){
            int delta = length2 - length1;
            int i = 0;
            while(i < delta){
                ptrB = ptrB->next;
                ++i;
            }
        }
        while(1){
            if(ptrA == NULL || ptrB == NULL)
                return NULL;
            if(ptrA == ptrB)
                return ptrA;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
    }
};