// File: num025.cpp
// Author: lxw
// Date: 2015-06-07

/*
Num num025: Reverse Nodes in k-Group
Source: https://leetcode.com/problems/reverse-nodes-in-k-group/

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    int getLength(ListNode * head){
        int length = 0;
        while(head){
            ++length;
            head = head->next;
        }
        return length;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k <= 1){
            return head;
        }
        int length = getLength(head);
        return reverse(head, k, length);
    }
    ListNode * reverse(ListNode * head, int k, int length){
        if(length < k){
            return head;
        }
        ListNode * p = head;
        ListNode * q = head;
        ListNode * temp = NULL;
        int i = 0;
        while(i < k){
            temp = q->next;
            q->next = p;
            p = q;
            q = temp;
            ++i;
        }
        head->next = reverse(q, k, length - k);
        return p;
    }
};
