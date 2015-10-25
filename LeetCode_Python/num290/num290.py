#!/usr/bin/python2.7
# FileName: num290.py
# Author: lxw
# Date: 2015-10-23

"""
Num 290: Word Pattern
Source: https://leetcode.com/problems/word-pattern/

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

Credits:
Special thanks to @minglotus6 for adding this problem and creating all test cases.
"""
class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        patternDict = {}
        strDict = {}
        length = len(pattern)
        strList = str.split(" ")
        if length != len(strList):
            return False
        for index in xrange(length):
            if pattern[index] in patternDict.keys():
                if patternDict[pattern[index]] != strList[index]:
                    return False
                elif strDict[strList[index]] != pattern[index]:
                    return False
            else:
                patternDict[pattern[index]] = strList[index]
                if strList[index] in strDict:
                    return False
                else:
                    strDict[strList[index]] = pattern[index]
        return True