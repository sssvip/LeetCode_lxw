// File: num143.cpp
// Author: lxw
// Date: 2015-09-22

/*
Num num143: Reorder List
Source: https://leetcode.com/problems/reorder-list/

Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//Space: O(1). Time: O(n).
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
        ListNode * slow = head;
        ListNode * fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse the list start from slow.
        ListNode * sentinel = new ListNode(0);
        sentinel->next = slow;
        ListNode * prev = sentinel;
        ListNode * temp = NULL;
        ListNode * cur = slow;
        
        while(cur){
            temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        sentinel->next->next = NULL;
        delete sentinel;
        
        ListNode * temp1;
        while(head != slow && prev != NULL){
            temp = head->next;
            head->next = prev;
            temp1 = prev->next;
            prev->next = temp;
            prev = temp1;
            head = temp;
        }
        if(prev == NULL)    //even
            head->next = NULL;
    }
};

//Space: O(n). Time: O(n).
/*
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL)
            return;
        vector<ListNode *> nodes;
        while(head != NULL){
            nodes.push_back(head);
            head = head->next;
        }
        int length = nodes.size();
        int i = 0;
        int j = length - 1;
        while(i < j){
            nodes[i]->next = nodes[j];
            nodes[j]->next = nodes[i+1];
            ++i;
            --j;
        }
        nodes[i]->next = NULL;
    }
};*/



//Space: O(n). Time: O(n).
/*
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL)
            return;
        vector<ListNode *> nodes;
        while(head != NULL){
            nodes.push_back(head);
            head = head->next;
        }
        int length = nodes.size();
        int i = 0;
        int j = length - 1;
        while(i < j){
            nodes[i]->next = nodes[j];
            nodes[j]->next = nodes[i+1];
            ++i;
            --j;
        }
        nodes[i]->next = NULL;
    }
};*/

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
	//LinkedList
    ListNode ln1 = ListNode(1);
    ListNode ln2 = ListNode(2);
    ListNode ln3 = ListNode(3);
    ListNode ln4 = ListNode(4);
    ln1.next = &ln2;
    ln2.next = &ln3;
    ln3.next = &ln4;
    showList(&ln1);
    Solution sol;
    sol.reorderList(&ln1);
    showList(&ln1);
}