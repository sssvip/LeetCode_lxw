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
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL){
            return head;
        }
        int length = 1;
        ListNode * current = head;
        while(current->next){
            ++length;   // current->next
            current = current->next;    //current != NULL
        }
        //Now 'current' points to the tail of the list.
        //Important: circle the list.
        current->next = head;
        k %= length;
        if(k){
            for(int i = 0; i < length - k - 1; ++i){
                head = head->next;
            }
            ListNode * newHead = head->next;
            head->next = NULL;
            return newHead;
        }
        else{
            current->next = NULL;
            return head;
        }
    }
};
void showList(ListNode * head){
    if(head == NULL){
        return;
    }
    while(head->next){
        cout << head->val << ", ";
        head = head->next;
    }
    cout << head->val << endl;
}
int main(void){
	ListNode ln1 = ListNode(1);
	ListNode ln2 = ListNode(2);
	ln1.next = &ln2;
	Solution sol;
	ListNode * head = sol.rotateRight(&ln1, 2);
    showList(head);
	return 0;
}
