#!/usr/bin/python2.7
# FileName: num500.py
# Author: lxw
# Date: 2017-02-15

"""
Num 500: Keyboard Row
Source: https://leetcode.com/problems/keyboard-row/?tab=Description

Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
"""

class Solution(object):
    def inSet(self, word, rowSet):
        index = 0
        length = len(word)
        while index < length and word[index] in rowSet:
            index += 1
        if index == length:
            return 1
        elif index > 0:
            return -1   #in multiple rows
        else:
            return 0    #not in this "rowSet", may be in the other "rowSet"
        
    def findWords1(self, words):
        """
        :type words: List[str]
        :rtype: List[str]

        Time: O(n) 45ms
        Space: O(1)
        """
        retList = []
        if len(words) == 0:
            return retList
        
        firstRow = set(["q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P"]) 
        secondRow = set(["a", "s", "d", "f", "g", "h", "j", "k", "l", "A", "S", "D", "F", "G", "H", "J", "K", "L"])
        thirdRow = set(["z", "x", "c", "v", "b", "n", "m", "Z", "X", "C", "V", "B", "N", "M"])
        
        for word in words:
            if word == "":
                retList.append(word)
                continue
            
            retV = self.inSet(word, firstRow)
            if retV == 1:
                retList.append(word)
                continue
            elif retV == -1:
                continue
            
            retV = self.inSet(word, secondRow)
            if retV == 1:
                retList.append(word)
                continue
            elif retV == -1:
                continue
            
            retV = self.inSet(word, thirdRow)
            if retV == 1:
                retList.append(word)
                continue
            elif retV == -1:
                continue
            
        return retList


    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]

        Time: O(n) 52ms
        Space: O(1)
        """
        retList = []
        if len(words) == 0:
            return retList
        firstRow = set("qwertyuiop")
        secondRow = set("asdfghjkl")
        thirdRow = set("zxcvbnm")
        for word in words:
            wordSet = set(word.lower())
            if wordSet.issubset(firstRow) or wordSet.issubset(secondRow) or wordSet.issubset(thirdRow):
                retList.append(word)
        return retList


def main():
    sol = Solution()
    words = ["Hello", "Alaska", "Dad", "Peace"]
    print sol.findWords(words)


if __name__ == "__main__":
    main()