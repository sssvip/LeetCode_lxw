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
        
        """
        #Method 1:
        Time: O(n)  72ms
        length = len(word)
        if length < 2:
            return True
        if ord(word[-1]) < 91: #Uppercase
            for letter in word[-2::-1]:
                if ord(letter) > 90: #Lowercase
                    return False
        else:   #Lowercase
            for letter in word[-2:0:-1]:
                if ord(letter) < 97: #Uppercase
                    return False
        return True
        """
        
        #Method 2:
        #Time: O(n) 49ms
        return re.match("^[A-Z]*$|^[a-z]*$|^[A-Z][a-z]*$", word) != None