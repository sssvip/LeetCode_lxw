// File: num203.cpp
// Author: lxw
// Date: 2015-08-09

/*
Num 203: Remove Linked List Elements
Source: https://leetcode.com/problems/remove-linked-list-elements/

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * prev = new ListNode(0);
        prev->next = head;
        ListNode * current = head;
        ListNode * sentinel = prev;
        ListNode * temp = NULL;
        while(current != NULL){
            if(current->val == val){
                prev->next = current->next;
                temp = current;
                current = current->next;
                delete temp;
            }
            else{
                prev = current;
                current = current->next;
            }
        }
        current = sentinel->next;
        delete sentinel;
        return current;
    }
};