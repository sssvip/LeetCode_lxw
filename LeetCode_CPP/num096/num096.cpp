// File: num096.cpp
// Author: lxw
// Date: 2015-07-29

/*
Num 096: Unique Binary Search Trees
Source: https://leetcode.com/problems/unique-binary-search-trees/

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
public:
    int numTrees(int n) {
        if(n <= 1)
            return 1;
        vector<int> counts(size_t(n + 1), 0);
        counts[0] = 1;
        counts[1] = 1;
        int mid = 0;
        for(int i = 2; i <= n; ++i){
            mid = i >> 1;   // i / 2
            for(int j = 0; j < mid; ++j){   //j <= mid-1
                counts[i] += ((counts[j] * counts[i-1-j]) << 1);    //counts[i] += counts[j] * counts[i-1-j] * 2
            }
            if(i & 0x01){   // odd
                counts[i] += counts[mid] * counts[mid];
            }
        }
        return counts[n];
    }
};