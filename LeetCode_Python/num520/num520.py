#!/usr/bin/python2.7
# FileName: num520.py
# Author: lxw
# Date: 2017-03-11

"""
Num 520: Detect Capital
Source: https://leetcode.com/problems/detect-capital/?tab=Description

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
"""
class Solution(object):
    def detectCapitalUse(self, word):
        """
        :type word: str
        :rtype: bool
        """
        length = len(word)
        if length < 2:
            return True
        if word[-1] < 91: #Uppercase
            for letter in word[-2::-1]:
                if letter > 90: #Lowercase
                    return False
        else:   #Lowercase
            for letter in word[-2:0:-1]:
                if letter < 97: #Uppercase
                    return False
        return True


def main():
    sol = Solution()
    words = ["Hello", "Alaska", "Dad", "Peace"]
    print sol.findWords(words)


if __name__ == "__main__":
    main()