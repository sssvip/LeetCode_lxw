// File: num092.cpp
// Author: lxw
// Date: 2015-07-17

/*
Num 092: Reverse Linked List II 
Source: https://leetcode.com/problems/reverse-linked-list-ii/

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //最开始时对m分情况讨论m>1和m==1,这时就可以通过添加一个哨兵节点,来避免分情况讨论
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n || head == NULL){
            return head;
        }
        ListNode * newHead = new ListNode(0);
        newHead->next = head;
        ListNode * prev = newHead;
        ListNode * p2 = NULL;
        ListNode * p1 = head;
        int i = 1;
        while(i < m){
            prev = p1;
            p1 = p1->next;
            ++i;
        }
        ListNode * temp = p1;
        ListNode * current = NULL;
        while(i <= n){
            current = p1->next;
            p1->next = p2;
            p2 = p1;
            p1 = current;
            ++i;
        }
        temp->next = p1;
        prev->next = p2;
        temp = newHead;
        newHead = newHead->next;
        delete temp;
        return newHead;
    }
};