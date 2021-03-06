#!/usr/bin/python2.7
# FileName: num389.py
# Author: lxw
# Date: 2016-08-30

"""
Num 389: Find the Difference
Source: https://leetcode.com/problems/find-the-difference/

Given two strings s and t which consist of only lowercase letters.
String t is generated by random shuffling string s and then add one more letter at a random position.
Find the letter that was added in t.

Example:
Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.
"""

class Solution(object):
    #Method 1 88ms
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        length = len(s)
        result = 0
        for i in xrange(length):
            result += (ord(t[i]) - ord(s[i]))
        result += ord(t[length])
        return chr(result)

    #Method 2: better 60ms
    def findTheDifference1(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        length = len(s)
        result = 0
        for i in xrange(length):
            result ^= ord(s[i])
            result ^= ord(t[i])
        result ^= ord(t[length])
        return chr(result)
def main():
    sol = Solution()
    print "result:", sol.findTheDifference("abcd", "caedb")
    print "result1:", sol.findTheDifference1("abcd", "caedb")

if __name__ == "__main__":
    main()
