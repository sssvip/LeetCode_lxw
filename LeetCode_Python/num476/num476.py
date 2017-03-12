#!/usr/bin/python2.7
# FileName: num476.py
# Author: lxw
# Date: 2017-03-12

"""
Num 476: Number Complement
Source: https://leetcode.com/problems/number-complement/?tab=Description

Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
"""

class Solution(object):
    def findComplement(self, num):
        """
        Time: O(1). 42ms.
        :type num: int
        :rtype: int
        """
        result = 0
        two = 1
        while num:
            if num % 2 == 0:
                result += two
            num /= 2
            two *= 2
        return result