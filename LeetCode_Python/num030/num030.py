#!/usr/bin/python2.7
# FileName: num030.py
# Author: lxw
# Date: 2015-07-03

"""
Num 030: Substring with Concatenation of All Words
Source: https://leetcode.com/problems/substring-with-concatenation-of-all-words/#/description

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
"""

import copy

class Solution(object):

    def findSubstring(self, s, words):
        """
        TLE:Time Limit Exceeded
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        result = []
        if not words:
            return result
        wLength = len(words[0])
        index = 0
        sLength = len(s)
        wordsDict = {}
        for word in words:
            if word in wordsDict:
                wordsDict[word] += 1
            else:
                wordsDict[word] = 1
        for index in xrange(sLength):
            subStr = s[index:index+wLength]
            tempIndex = index
            wordsDictCopy = copy.deepcopy(wordsDict)
            while 1:
                if subStr in wordsDictCopy:
                    wordsDictCopy[subStr] -= 1
                    if wordsDictCopy[subStr] == 0:
                        del wordsDictCopy[subStr]
                        if len(wordsDictCopy) == 0: #exit
                            result.append(index)
                            index += len(words) * wLength
                            break
                    tempIndex += wLength
                    subStr = s[tempIndex:tempIndex+wLength]
                else:
                    break
        return result


if __name__ == '__main__':
    sol = Solution()
    s = "afoobarthenamebarfoo"
    words = ["foo", "bar"]
    print "result:", sol.findSubstring(s, words)
