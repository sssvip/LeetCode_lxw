#!/usr/bin/python2.7
# FileName: num205_in.py
# Author: lxw
# Date: 2015-04-29

"""
Num 205: Isomorphic Strings
Source : https://leetcode.com/problems/isomorphic-strings/

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
    You may assume both s and t have the same length.
"""

"""
Note: No two characters may map to the same character but a character may map to itself. e.g. "ab", "aa"
"""

class Solution(object):
    def __init__(self):
        pass

    def isIsomorphic(self, s, t):
        mapDict = {}   # "alphabet mapping Dict"
        length = len(s)
        result = True
        for index in xrange(length):
            if s[index] in mapDict.keys():    #compare this with get() method. get() seems much faster.
                value = mapDict[s[index]]
                if value != t[index]:
                    result = False
                    break
            else:
                if t[index] in mapDict.values():
                    result = False
                    break
                else:
                    mapDict[s[index]] = t[index]
        return result


def main():
    s = Solution()
    isomDict = {"egg":"add", "foo":"bar", "paper":"title", "ab":"aa"}
    for item in isomDict:
        print item, isomDict[item], " : ",
        print(s.isIsomorphic(item, isomDict[item]))


if __name__ == '__main__':
    main()
else:
    print("Being imported as a module.")
