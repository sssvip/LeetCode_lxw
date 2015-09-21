// File: num082.cpp
// Author: lxw
// Date: 2015-07-05

/*
Num 082: Remove Duplicates from Sorted List II 
Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode * prev = new ListNode(0);
        ListNode * sentinel = prev;
        prev->next = head;
        ListNode * cur = head;
        ListNode * temp;
        int count;
        while(cur){
            count = 1;
            while(cur->next != NULL && cur->next->val == cur->val){
                ++count;
                temp = cur;
                cur = cur->next;
                delete temp;
            }
            if(count > 1){
                temp = cur;
                cur = cur->next;
                delete temp;
            }
            else{
                prev->next = cur;
                prev = cur;
                cur = cur->next;
            }
        }
        prev->next = NULL;
        head = sentinel->next;
        delete sentinel;
        return head;
    }
};

int main(void){
	Solution sol;
	//LinkedList
    ListNode * ln1 = new ListNode(1);
    ListNode * ln2 = new ListNode(2);    
    ListNode * ln3 = new ListNode(3);
    ListNode * ln4 = new ListNode(3);
    ListNode * ln5 = new ListNode(4);
    ListNode * ln6 = new ListNode(5);
    ln1->next = ln2;
    ln2->next = ln3;
    ln3->next = ln4;
    ln4->next = ln5;
    ln5->next = ln6;
    //showList(ln1);
	ListNode * head = sol.deleteDuplicates(ln1);
	showList(head);
	ListNode * temp;
	while(head){
		temp = head;
		head = head->next;
		delete temp;
	}
    return 0;
}
