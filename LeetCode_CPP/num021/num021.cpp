// File: num021.cpp
// Author: lxw
// Date: 2015-06-01

/*
Num 021: Merge Two Sorted Lists
Source: https://leetcode.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode() : next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head1 = l1;
        ListNode * head2 = l2;
        ListNode * head = NULL;
        ListNode * current = NULL;
        if(head1 == NULL){
            return head2;
        }
        if(head2 == NULL){
            return head1;
        }
        if(head1->val < head2->val){
            head = head1;
            current = head1;
            head1 = head1->next;
        }
        else{
            head = head2;
            current = head2;
            head2 = head2->next;
        }
        while(head1 != NULL && head2 != NULL){
            if(head1->val < head2->val){
                current->next = head1;
                head1 = head1->next;
            }
            else{
                current->next = head2;
                head2 = head2->next;
            }
            current = current->next;
        }
        if(head1 != NULL){
            current->next = head1;
        }
        else{
            current->next = head2;
        }
        return head;
    }
};

int main(void)
{
    //Linked List 1
    ListNode * ln = new ListNode[5];
    for(int i = 0; i < 5; ++i){
        ln[i] = ListNode(i);
        cout << ln[i].val << " ";
    }
    cout << endl;
    for(int i = 0; i < 4; ++i){
        ln[i].next = &ln[i+1];
    }

    //Linked List 2
    ListNode ln1[8];
    for(int i = 0; i < 8; ++i){
        ln1[i] = ListNode(2*i-3);
        cout << ln1[i].val << " ";
    }
    cout << endl;
    for(int i = 0; i < 7; ++i){
        ln1[i].next = &ln1[i+1];
    }
    Solution sol;
    ListNode * result = sol.mergeTwoLists(&ln[0], &ln1[0]);
    while(result != NULL){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}
