// File: num275.cpp
// Author: lxw
// Date: 2015-09-05

/*
Num num275: H-Index II
Source: https://leetcode.com/problems/h-index-ii/

Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Hint:

Expected runtime complexity is in O(log n) and the input is sorted.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        if(length == 0)
            return 0;
        int start = 0;
        int end = length - 1;
        if(citations[start] >= length - start){
        	return length;
        }
        if(citations[end] < length - end){
        	return 0;
        }
        int mid = 0;
        while(start < end){
        	mid = (start + end) >> 1;	// /= 2
        	if(citations[mid] < length - mid)
        		start = mid + 1;	//not mid. otherwise deadcycle.
        	else
        		end = mid;	// not mid-1;
        }
        return length - end;
    }
};