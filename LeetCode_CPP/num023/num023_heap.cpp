// NOTE THE CASE THAT WE MODIFY THE DICT/LIST IN A LOOP.
// File: num023_heap.cpp
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

class cmp{
public:
    //DO NOT UNDERSTAND.
    bool operator()(ListNode* p1, ListNode* p2) const{
        return p1->val > p2->val;
    }
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

        //remove the empty list from the vector.  NOTE THE CASE THAT WE MODIFY THE DICT/LIST IN A LOOP.
        //for(int i = 0; i < length;){ //NO!NO!NO!NO!NO!NO!NO!NO!NO!NO!NO!NO!NO!NO!NO!
        for(int i = 0; i < lists.size();){
            if(lists[i] == NULL){
                lists.erase(lists.begin() + i);
            }
            else{
                ++i;
            }
        }

        length = lists.size();
        if(length < 1){
            return NULL;
        }
        if(length == 1){
            return lists[0];
        }

        //build heap for "first element in each list"
        make_heap(lists.begin(), lists.end(), cmp());

        ListNode ln(0);
        ListNode * current = &ln;
        ListNode * head = current;

        while(!lists.empty()){
            int curSize = lists.size();
            pop_heap(lists.begin(), lists.end(), cmp());
            current->next = lists[curSize-1];
            current = current->next;
            lists.pop_back();
            if(current->next != NULL){
                lists.push_back(current->next);
                push_heap(lists.begin(), lists.end(), cmp());
            }
        }
        return head->next;
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

