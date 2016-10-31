#!/usr/bin/python2.7
# FileName: num071.py
# Author: lxw
# Date: 2015-07-03

"""
Num 034: 
Source: 

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
"""

class Solution(object):
    def binSearch(self, nums, target, start, end):
        while start <= end:
            mid = (start + end) >> 1
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                end = mid - 1
            else:
                start = mid + 1
        return -1

    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(nums)
        index = self.binSearch(nums, target, 0, length-1)
        if index == -1:
            return [-1, -1]
        else:
            start = index
            end = index
            while start >= 0 and nums[start] == target:
                start -= 1
            start += 1

            while end < length and nums[end] == target:
                end += 1
            end -= 1
            return [start, end]

if __name__ == '__main__':
    sol = Solution()
    print sol.searchRange([1, 3, 3, 4, 5, 5, 5, 7, 7, 8, 8], 5)

