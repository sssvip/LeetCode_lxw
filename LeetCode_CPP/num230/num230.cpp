// File: num230.cpp
// Author: lxw
// Date: 2015-07-25

/*
Num num230: Kth Smallest Element in a BST
Source: https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.Show More Hint 
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0)
            return false;
        int length = sizeof(int) * 8 - 1;
        /* 有必要吗？
        int * array = new int[length];
        for(int i = 0; i < length; ++i){
            array[i] = 1 << i;
        }*/
        for(int i = 0; i < length; ++i){
            if(n == (1 << i)){
                return true;
            }
        }
        return false;
    }
};