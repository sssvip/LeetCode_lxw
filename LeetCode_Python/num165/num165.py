#!/usr/bin/python2.7
# FileName: num165.py
# Author: lxw
# Date: 2015-07-17

"""
Num num165.py: Compare Version Numbers
Source: https://leetcode.com/problems/compare-version-numbers/

Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37
Credits:
Special thanks to @ts for adding this problem and creating all test cases.
"""

class Solution:
    # @param {string} version1
    # @param {string} version2
    # @return {integer}
    def compareVersion(self, version1, version2):
        verList1 = version1.split('.')
        verList2 = version2.split('.')
        length1 = len(verList1)
        length2 = len(verList2)
        length = min(length1, length2)
        i = 0
        while i < length:
            if int(verList1[i]) < int(verList2[i]):
                return -1
            elif int(verList1[i]) > int(verList2[i]):
                return 1
            i += 1
        if length1 < length2:
            while i < length2:
                if int(verList2[i]) != 0:
                    return -1
                i += 1
            return 0
        elif length1 > length2:
            while i < length1:
                if int(verList1[i]) != 0:
                    return 1
                i += 1
            return 0
        else:
            return 0