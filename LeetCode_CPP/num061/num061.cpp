// File: num061.cpp
// Author: lxw
// Date: 2015-06-29

/*
Num num061: Rotate List
Source: https://leetcode.com/problems/rotate-list/

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//There is no trick for this problem. Some people used slow/fast pointers to find the tail node,
//but I don't see the benefit (in the sense that it doesn't reduce the pointer move op) to do so.
//So I just used one loop to find the length first.
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return head;

        int len = 1; // number of nodes
        ListNode *newH, *tail;
        newH = tail = head;

        while(tail->next){  // get the number of nodes in the list
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len){
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};
/*
class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL)
            return head;
        ListNode * current = head;
        int count = 0;
        for(int i = 0; i < k; ++i){
            current = current->next;
            ++count;
            if(current == NULL){
                k %= count;
                current = head;
                for(i = 0; i < k; ++i){
                    current = current->next;
                }
                break;
            }
        }
        if(current->next == NULL){
            current = head;
            if(current->next == NULL){
                return head;
            }
        }
        ListNode * temp = head;
        head = current->next;
        current->next = NULL;
        current = head;
        while(1){
            if(current->next == NULL){
                break;
            }
            current = current->next;
        }
        //current != NULL
        current->next = temp;
        return head;
    }
};
*/
