#!/usr/bin/python2.7
# FileName: num151.py
# Author: lxw
# Date: 2016-09-19

"""
Num num151: Reverse Words in a String
Source: https://leetcode.com/problems/reverse-words-in-a-string/

Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space.

click to show clarification.

Clarification:
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
"""

class Solution(object):
    """
    Time: O(n)  49ms.
    Space: O(n)
    """
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        sList = s.split()   #NOT split(" ")
        sList.reverse()
        return " ".join(sList)

    """
    Time: O(n)  49ms.
    Space: O(n)
    Stack: Two Stack?
    One Stack is OK.
    """
    def reverseWords1(self, s):
        """
        :type s: str
        :rtype: str
        """

if __name__ == "__main__":
    sol = Solution()
    print sol.reverseWords("the sky is blue")
