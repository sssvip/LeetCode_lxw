// File: num082.cpp
// Author: lxw
// Date: 2015-07-05

/*
Num 082: Remove Duplicates from Sorted List II 
Source: 

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
            return NULL;
        ListNode ln = ListNode(0);
        ListNode * newHead = &ln;
        ListNode * current = newHead;
        int value = head->val;
        int count = 0;
        while(head){        	
            if(head->val == value){
                ++count;
            }
            else{
                if(count == 1){                	
		            /*
		            //NOT OK. when came in the second time, ln1 will be modified instead of being recreated.
		            ListNode ln1 = ListNode(value);
		            current->next = &ln1;
		            */
                    current->next = new ListNode(value);
                    current = current->next;
                }
                count = 1;
                value = head->val;
            }
            head = head->next;            
        }
        if(count == 1){
        	/*
            ln = ListNode(value);   //NOTE: this is a 'trap and pitfall'. "ln = ListNode(value);" WON'T create a new ListNode, but modify the old ln in line 6;
            current->next = &ln;
            */
            current->next = new ListNode(value);            
        }
        return newHead->next;
    }
};
int main(void){
	Solution sol;
	//LinkedList
    ListNode ln1 = ListNode(1);
    ListNode ln2 = ListNode(2);
    ln1.next = &ln2;
    //showList(&ln1);
	ListNode * head = sol.deleteDuplicates(&ln1);
	showList(head);
    return 0;
}
