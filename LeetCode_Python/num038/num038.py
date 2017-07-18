#!/usr/bin/python3.6
# FileName: num038.py
# Author: lxw
# Date: 2017-07-18

"""
Num 038: Count and Say
Source: https://leetcode.com/problems/count-and-say/#/description

The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"
"""

class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n < 1:
            return ""        
        result = "1"
        for i in range(n-1):    # n >= 1
            length = len(result)
            count = 1
            str_list = []
            for i in range(length):
                if i < length-1:
                    if result[i] == result[i+1]:
                        count +=1
                    else:
                        str_list.append("{0}{1}".format(count, result[i]))
                        count = 1
                else:
                    str_list.append("{0}{1}".format(count, result[i]))
            result = "".join(str_list)
        return result
                    