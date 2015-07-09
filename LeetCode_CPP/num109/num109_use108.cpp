// File: num109_use108.cpp
// Author: lxw
// Date: 2015-07-09

/*
Num num109: Convert Sorted List to Binary Search Tree
Source: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int begin, int end) {
        if(begin == end)
            return new TreeNode(nums[begin]);
        if(begin > end)
            return NULL;
        int mid = ((long long)begin + (long long)end) >> 1;
        TreeNode * node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, begin, mid-1);
        node->right = sortedArrayToBST(nums, mid+1, end);
        return node;
    }
    //height balanced BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
            return NULL;
        if(length == 1) //necessary?
            return new TreeNode(nums[0]);
        return sortedArrayToBST(nums, 0, length-1);
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
    	vector<int> vi;
        while(head){
        	vi.push_back(head->val);
        	head = head->next;
        }
        return sortedArrayToBST(vi);
    }
};