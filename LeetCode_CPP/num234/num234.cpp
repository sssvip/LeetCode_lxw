// File: num234.cpp
// Author: lxw
// Date: 2015-07-24

/*
Num num234: Palindrome Linked List
Source: https://leetcode.com/problems/palindrome-linked-list/

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Method 1:
//Time: O(n)	Space: O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> elements;
        while(head){
            elements.push_back(head->val);
            head = head->next;
        }
        int length = elements.size();
        int start = 0;
        int end = length - 1;
        while(start < end){
            if(elements[start++] != elements[end--])
                return false;
        }
        return true;
    }
};

//Method 2:
//Time: O(n)	Space: O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
 //Iterative
    ListNode* reverseList(ListNode* head) {
        ListNode * p1 = head;
        ListNode * p2 = NULL;
        ListNode * current = NULL;
        while(p1){
            current = p1->next;
            p1->next = p2;
            p2 = p1;
            p1 = current;
        }
        return p2;
    }    
public:
    bool isPalindrome(ListNode* head) {
        vector<int> elements;
        int length = 0;
        ListNode * current = head;
        while(current){
            current = current->next;
            ++length;
        }
        current = head;
        length >>= 1;   //length /= 2;
        int i = 0;
        while(i < length){
            current = current->next;
            ++i;
        }
        current = reverseList(current);
        i = 0;
        while(i < length){
            if(head->val != current->val)
                return false;
            head = head->next;
            current = current->next;
            ++i;
        }
        return true;
    }
};