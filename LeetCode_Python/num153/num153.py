#!/usr/bin/env python3
# FileName: num153.py
# Author: lxw
# Date: 2017-04-17

"""
Num 153: Find Minimum in Rotated Sorted Array
Source: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/#/description

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
"""

class Solution(object):
    """
    Time: O(n). 62ms.
    BAD
    """
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length < 1:
            return None
        length -= 1
        for index in range(length):
            if nums[index] > nums[index+1]:
                return nums[index+1]
        
        return nums[0]

    """
    Time: O(logn). 49ms.
    GOOD
    """
    def findMin1(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length < 1:
            return None
        start = 0
        end = length-1
        while start < end:
            if nums[start] < nums[end]:
                return nums[start]
            mid = (start + end) >> 1
            if start == mid:
                return nums[start] if nums[start] < nums[end] else nums[end]
            if nums[mid] > nums[start]:
                start = mid + 1
            else:   #nums[mid] < nums[start]
                end = mid   #not mid - 1
        return nums[start]

    """
    Time: O(logn). 42ms.
    BETTER
    """
    def findMin2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length < 1:
            return None
        start = 0
        end = length-1
        while start < end:
            if nums[start] < nums[end]:
                return nums[start]
            mid = (start + end) >> 1
            if nums[mid] > nums[end]:
                start = mid + 1
            else:   #nums[mid] < nums[start]
                end = mid   #not mid - 1
        return nums[start]


if __name__ == '__main__':
    sol = Solution()
    nums = [4, 5, 6, 7, 0, 1, 2]
    print sol.findMin1(nums)
    nums = [0, 1, 2, 4, 5, 6, 7]
    print sol.findMin1(nums)
    nums = [2, 1]
    print sol.findMin1(nums)
    nums = [1]
    print sol.findMin1(nums)
        