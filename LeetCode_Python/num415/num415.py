#!/usr/bin/python2.7
# FileName: num415.py
# Author: lxw
# Date: 2016-10-13

"""
Num 415: Add Strings
Source: https://leetcode.com/problems/add-strings/

Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
"""

class Solution(object):
    """
    Time: O(n) 65 ms
    Space: O(n)
    """
    def addStrings(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        len1 = len(num1)
        len2 = len(num2)
        num3List = []
        carry = 0
        while len1 > 0 or len2 > 0:
            len1 -= 1
            len2 -= 1
            digit1 = 0 if len1 < 0 else ord(num1[len1]) - 48
            digit2 = 0 if len2 < 0 else ord(num2[len2]) - 48
            temp = digit1 + digit2 + carry
            carry = 0 if temp < 10 else 1
            temp = temp if temp < 10 else temp - 10
            num3List.append(chr(temp + 48))

        if carry == 1:
            num3List.append(chr(carry + 48))
        return "".join(num3List[::-1])

    """
    Shit
    Time: O(n) 742 ms
    Space: O(n)

    A lot of special cases need to be noted.
    """
    def addStrings_shit(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        #No need to turn into list
        num1List = list(num1)
        len1 = len(num1List)
        num2List = list(num2)
        len2 = len(num2List)

        big = 0
        small = 0 
        if len1 > len2:
            big = len1
            small = len2
        else:
            big = len2
            small = len1

        num3List = [""] * (big + 1)
        carry = 0

        while small != 0:
            len1 -= 1
            len2 -= 1
            small -= 1
            temp = ord(num1List[len1]) + ord(num2List[len2]) - 96 + carry #ord('0')
            if temp >= 10:
                carry = 1
                temp -= 10
            else:
                carry = 0
            num3List[big] = chr(temp + 48)
            big -= 1

        while len1 != 0:
            len1 -= 1
            temp = ord(num1List[len1]) + carry - 48
            if temp >= 10:
                carry = 1
                temp -= 10
            else:
                carry = 0
            num3List[big] = chr(temp + 48)
            print num3List
            big -= 1

        while len2 != 0:
            len2 -= 1
            temp = ord(num2List[len2]) + carry - 48
            if temp >= 10:
                carry = 1
                temp -= 10
            else:
                carry = 0
            num3List[big] = chr(temp + 48)
            big -= 1

        if carry == 0:
            return ''.join(num3List[1:])
        else:
            print "carry == 1"
            num3List[0] = chr(carry + 48)
            return ''.join(num3List)

def main():
    sol = Solution()
    print sol.addStrings("408", "5")
    print sol.addStrings("1", "9")

if __name__ == "__main__":
    main()