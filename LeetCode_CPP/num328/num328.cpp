// File: num328.cpp
// Author: lxw
// Date: 2016-04-03

/*
Num num328: Odd Even Linked List
Source: https://leetcode.com/problems/odd-even-linked-list/

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...

Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode * odd = head;
        ListNode * even = head->next;   //head->next != NULL; so, even is not NULL;
        ListNode * oddCur = head;
        ListNode * evenCur = even;
        ListNode * cur = evenCur->next;
        while(cur){
            oddCur->next = cur;
            evenCur->next = cur->next;
            oddCur = oddCur->next;
            evenCur = evenCur->next;
            cur = (evenCur == NULL ? NULL : evenCur->next);
        }
        if(evenCur){
            evenCur->next == NULL;
        }
        oddCur->next = even;
        return head;
    }
};