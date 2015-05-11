#!/usr/bin/python2.7
# FileName: num003_better.py
# Author: lxw
# Date: 2015-05-11

"""
Num 003: Longest Substring Without Repeating Characters
Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
"""

class Solution(object):
    def __init__(self):
        pass

    def lengthOfLongestSubstring(self, s):
        length = len(s)
        letterDict = {}
        maxLength = 0
        start = 0
        tempMax = 0
        for index in xrange(length):
            if letterDict.get(s[index]) is None or letterDict.get(s[index]) < start:
                letterDict[s[index]] = index
                tempMax = index - start + 1
            else:
                tempMax = index - start
                if tempMax > maxLength:
                    maxLength = tempMax
                start = letterDict[s[index]] + 1
                letterDict[s[index]] = index
        if tempMax > maxLength:
            maxLength = tempMax

        return maxLength


def main():
    s = Solution()
    #string = "abcdabcabcabc"
    #print(string)
    while 1:
        string = raw_input("Please input a string:")
        if not string:
            break
        print(s.lengthOfLongestSubstring(string))


if __name__ == '__main__':
    main()
else:
    print("Being imported as a module.")

