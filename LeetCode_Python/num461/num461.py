#!/usr/bin/python2.7
# FileName: num461.py
# Author: lxw
# Date: 2017-01-03

"""
Num 461: Hamming Distance
Source: https://leetcode.com/problems/hamming-distance/

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.
"""


class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        x = x ^ y
        distance = 0
        while x:
            x = x & (x-1)   #remove one bit(the value of this bit is 1)
            distance += 1
        return distance