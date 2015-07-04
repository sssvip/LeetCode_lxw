// File: num086.cpp
// Author: lxw
// Date: 2015-07-04

/*
Num 086: Partition List
Source: https://leetcode.com/problems/partition-list/

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL){
            return head;
        }
        ListNode * smallHead = NULL;
        ListNode * largeHead = NULL;
        ListNode * small = NULL;
        ListNode * large = NULL;
        while(head){
            if(head->val < x){
                if(smallHead){
                    small->next = head;
                    small = head;
                }
                else{
                    smallHead = head;
                    small = head;
                }
            }
            else{
                if(largeHead){
                    large->next = head;
                    large = head;
                }
                else{
                    largeHead = head;
                    large = head;
                }
            }
            head = head->next;
        }
        if(smallHead){
            small->next = largeHead;
            if(largeHead){
                large->next = NULL;
            }
            return smallHead;
        }
        else{
            large->next = NULL;
            return largeHead;
        }
    }
};