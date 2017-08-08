#!/usr/bin/python2.7
# FileName: num001.py
# Author: lxw
# Date: 2014-12-31

"""
Num 001: Two Sum

Source: https://leetcode.com/problems/two-sum/

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
"""

class Solution:
    # @return a tuple, (index1, index2)
    '''
    #NO:TLE(Time Limit Exceeded). list.index() is much too slow: O(n).
    def twoSum(self, num, target):
        index0 = 0
        index1 = -1
        for item in num:
            index0 += 1
            other = target - item
            try:
                index1 = num[index0:].index(other)
                index1 += index0 + 1
            except ValueError:
                continue
            else:
                break
        return index0, index1
    '''
    # OK: A really SIMPLE & CLEAN solution.
    def twoSum(self, num, target):
        s = {}
        for i, element in enumerate(num):
            i2 = s.get(target-element)
            if i2 != None:
                return i2+1, i+1
            else:
                s[element] = i

def main():
    sol = Solution()
    num = []
    for i in xrange(1000):
        num.append(i)
    num = [0, 4, 3, 4, 0, 0, 5]
    print(sol.twoSum(num, 9))
    
main()
