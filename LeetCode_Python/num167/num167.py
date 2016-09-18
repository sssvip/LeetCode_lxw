#!/usr/bin/python2.7
# FileName: num167.py
# Author: lxw
# Date: 2015-09-18

"""
Num num167: Two Sum II - Input array is sorted
Source: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
"""

class Solution(object):
    #protected: _func()
    #private: __func()
    def __binSearch(self, numbers, target, start, end):
        while 1:
            if start > end:
                return -1
            mid = (start + end) >> 1
            if numbers[mid] == target:
                return mid
            elif numbers[mid] > target:
                #print "little -> target: ", target, ", start: ", start, ", mid: ", mid, ", end:", end
                end = mid - 1
            else:   #numbers[mid] < target:
                #print "big -> target: ", target, ", start: ", start, ", mid: ", mid, ", end:", end
                start = mid + 1

    """
    Bad
    Time: < O(nlogn)    145ms.
    Space: O(1)
    Binary Search
    """
    def twoSum1(self, numbers, target):
        length = len(numbers)
        for index in xrange(length):
            deltaIndex = self.__binSearch(numbers, target - numbers[index], index+1, length-1)
            print "deltaIndex: ", deltaIndex
            if deltaIndex != -1:
                return [index+1, deltaIndex+1]
        return []


    """
    OK
    Time: O(n)  58ms.
    Space: O(n)
    """
    def twoSum2(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(numbers)
        if length == 0:
            return []
        numDict = {}
        #O(n)
        for index in xrange(length):
            if numbers[index] in numDict:
                numDict[numbers[index]].append(index)
            else:
                numDict[numbers[index]] = [index]
        #O(n)
        #minuend - subtrahend = delta
        for index in xrange(length):
            delta = target - numbers[index]
            flag = False
            if delta in numDict:
                for num in numDict[delta]:
                    if num != index:
                        return [index+1, num+1]
        return []

    """
    Good
    Time: O(n)  56ms.
    Space: O(n)
    Improve algorithm twoSum2.
    """
    def twoSum3(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(numbers)
        if length == 0:
            return []
        numDict = {}
        #O(n)
        for index in xrange(length):
            delta = target - numbers[index]
            if delta in numDict:
                return [numDict[delta][0]+1, index+1]
            if numbers[index] in numDict:
                numDict[numbers[index]].append(index)
            else:
                numDict[numbers[index]] = [index]
        return []

    """
    Great
    Time: O(n)  55ms.
    Space: O(1)
    Two Pointers
    http://blog.csdn.net/xudli/article/details/42290269
    """
    def twoSum4(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        length = len(numbers)
        if length < 2:
            return []
        head = 0    
        tail = length - 1
        if numbers[head] > target:
            return []
        while head < tail:
            sumOf2 = numbers[head] + numbers[tail]
            if sumOf2 == target:
                return [head+1, tail+1]
            elif sumOf2 > target: 
                tail -= 1
            else:
                head += 1
        return []

if __name__ == "__main__":
    sol = Solution()    # OK?
    numbers = [2, 7, 11, 15]
    print sol.twoSum1(numbers, 9)
    print sol.twoSum2(numbers, 9)
    print sol.twoSum3(numbers, 9)
    numbers = [2, 3, 4]
    print sol.twoSum4(numbers, 6)
    numbers = [0, 0, 3, 4]
    print sol.twoSum4(numbers, 6)
