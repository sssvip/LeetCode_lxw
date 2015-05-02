#!/usr/bin/python2.7
#File: num003.py
#Author: lxw
#Time: 2015-05-02
#Usage: Num 003: Longest Substring Without Repeating Characters.

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
            if letterDict.get(s[index]) is None:
                letterDict[s[index]] = index
                tempMax = index - start + 1
            else:
                tempMax = index - start
                if tempMax > maxLength:
                    maxLength = tempMax
                start = letterDict[s[index]] + 1
                self.filterDict(letterDict, start)
                letterDict[s[index]] = index
        if tempMax > maxLength:
            maxLength = tempMax

        return maxLength


    def filterDict(self, aDict, targetValue):
        """
        Filter out the element whose value is smaller than specific value.
        """
        for key, value in aDict.items():
            if value < targetValue:
                del aDict[key]


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

