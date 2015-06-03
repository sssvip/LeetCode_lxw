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
        ListNode ln = ListNode(0);
        ListNode * current = &ln;
        ListNode * head = current;
        int length = lists.size();
        if(length == 1){
            return lists[0];
        }
        else{
            mergeRecursive(lists, current, length);
            return head->next;
        }
    }
    void mergeRecursive(vector<ListNode*>& lists, ListNode* current, int length) {
        int min = 0x7fffffff;
        int index = -1;
        for(int i = 0; i < length; ++i){
            if(lists[i] != NULL){
                if(lists[i]->val <= min){
                    min = lists[i]->val;
                    index = i;
                }
            }
        }
        if(index != -1){   // Not finished.
            current->next = lists[index];
            lists[index] = lists[index]->next;
            //current = lists[index];   //NO.NO.NO.NO.NO.NO.NO.NO.NO.NO.NO.NO.NO.NO.NO.NO.
            current = current->next;
            mergeRecursive(lists, current, length);
        }
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

