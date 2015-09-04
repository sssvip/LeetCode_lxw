// File: num147.cpp
// Author: lxw
// Date: 2015-09-04

/*
Num num147: Insertion Sort List
Source: https://leetcode.com/problems/insertion-sort-list/

Sort a linked list using insertion sort.
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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode * cur = head->next;
        ListNode * temp;
        ListNode * prev = head;
        ListNode * pt;
        int bound = 1;
        int i = 0;
        while(cur){
            i = 0;
            pt = head;
            for(; i < bound; ++i){
                if(pt->val <= cur->val){
                    prev = pt;
                    pt = pt->next;  //assert(pt != NULL);
                }
                else{
                    break;
                }
            }
            temp = cur->next;
            if(i != bound){
                if(i == 0){
                    cur->next = head;
                    head = cur;
                }
                else{
                    cur->next = pt;
                    prev->next = cur;
                }
                for(; i < bound; ++i){
                    prev = pt;
                    pt = pt->next;
                }
                prev->next = temp;
            }
            cur = temp;
            ++bound;
        }
        return head;
    }
};