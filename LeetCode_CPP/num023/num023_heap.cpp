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

/*
C++ STL 还提供了一个priority_queue（优先级队列），它是一个拥有权值观念的队列。

1. 它是队列，所以只能在底端加入元素，从顶端取出元素。
2. 它带有权值观念，所以其中的元素并非依照 push 的次序排列，而是依照权值排列，每次 pop 出权值最高的元素。

priority_queue其实就是调用make_heap()、push_heap()、pop_heap()实现的，所以它的底层就是基于heap。只不过经过封装以后，使用更加方便了。

priority_queue的解法,本题没有给出。
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

//Reference: http://blog.csdn.net/lisonglisonglisong/article/details/45942605

class Cmp{
public:
    /*
    // num023_heap.cpp:78:52:   required from here
    // /usr/include/c++/4.8/bits/stl_heap.h:313:40: error: no match for call to ‘(Cmp) (ListNode*&, ListNode*&)’
    // So the following method is wrong.
    bool operator()(ListNode* p2) const{
        return p->val > p2->val;
    }
    */
    bool operator()(ListNode*& p1, ListNode*& p2) const{
        return p1->val > p2->val;   //why '>' instead of '<' ?
    }
};

class Solution {
private:
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
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

        int length = lists.size();
        if(length < 1){
            return NULL;
        }
        if(length == 1){
            return lists[0];
        }

        //build heap for "first element in each list"
        make_heap(lists.begin(), lists.end(), Cmp());

        ListNode ln(0);
        ListNode * current = &ln;
        ListNode * head = current;

        //固定搭配pop_heap()接pop_back(), push_back()接push_heap()
        while(!lists.empty()){
            int curSize = lists.size();
            pop_heap(lists.begin(), lists.end(), Cmp());
            //The element poped is not deleted, but moved at the index of 'curSize-1'.
            current->next = lists[curSize-1];
            current = current->next;
            lists.pop_back();
            if(current->next != NULL){
                lists.push_back(current->next);
                push_heap(lists.begin(), lists.end(), Cmp());
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

    ListNode ln4(1);
    ListNode ln5(3);
    ListNode ln6(4);
    ln4.next = &ln5;
    ln5.next = &ln6;

    vector<ListNode*> l1;
    l1.push_back(&ln1);
    l1.push_back(&ln4);

    ListNode * head = sol.mergeKLists(l1);
    while(head != NULL){
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}
