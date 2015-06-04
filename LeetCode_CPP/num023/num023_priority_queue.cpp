// File: num023_priority_queue.cpp
// Author: lxw
// Date: 2015-06-04

/*
Num 023: Merge k Sorted Lists
Source: https://leetcode.com/problems/merge-k-sorted-lists/

Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int length = lists.size();
        if(length < 1){
            return NULL;
        }
        if(length == 1){
            return lists[0];
        }

        {
            ;
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
