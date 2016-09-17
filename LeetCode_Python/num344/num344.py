#!/usr/bin/python2.7
# FileName: num344.py
# Author: lxw
# Date: 2016-09-17

"""
Num 344: Reverse String
Source: https://leetcode.com/problems/reverse-string/

Write a function that takes a string as input and returns the string reversed.

Example:
Given s = "hello", return "olleh".
"""

class Solution(object):
    """
    Time: O(n) 42ms.
    Space: O(n)
    """
    def reverseString1(self, s):
        """
        :type s: str
        :rtype: str
        """
        return s[::-1]

    """
    Time: O(n)  66ms.
    Space: O(n)
    """
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        charList = ['0'] * length
        for index in xrange(length):
            charList[index] = s[length - index - 1]
        return "".join(charList)
    

def main():
    sol = Solution()
    string = "hello"    
    print sol.reverseString(string)
    print sol.reverseString1(string)

if __name__ == "__main__":
    main()
