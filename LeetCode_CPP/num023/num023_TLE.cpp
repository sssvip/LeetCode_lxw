// Time Limit Exceeded.
// File: num023.cpp
// Author: lxw
// Date: 2015-06-03

/*
Num 023: Merge k Sorted Lists
Source: https://leetcode.com/problems/merge-k-sorted-lists/

Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.

*/

#include <iostream>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int length = lists.size();
        if(length < 1){
            return NULL;
        }
        if(length == 1){
            return lists[0];
        }
        else{
            ListNode * head = lists[0];
            for(int i = 1; i < length; ++i){
                head = mergeTwoLists(head, lists[i]);
            }
            return head;
        }
    }
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
    Solution sol;
    ListNode ln1(0);
    ListNode ln2(2);
    ListNode ln3(5);
    ln1.next = &ln2;
    ln2.next = &ln3;
    ListNode * lnP = &ln1;

    vector<ListNode*> l1;
    l1.push_back(&ln1);
    cout << sol.mergeKLists(l1)->val << endl;
    return 0;
}

