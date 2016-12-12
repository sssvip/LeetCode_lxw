#!/usr/bin/python2.7
#coding: utf-8
# FileName: num371.py
# Author: lxw
# Date: 2016-12-11

"""
Num 371: Sum of Two Integers
Source: https://leetcode.com/problems/sum-of-two-integers/

Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
"""

class Solution(object):
    #NOT OK, this method is not fit for Python.
    def getSum_Java_YES_Python_NO(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        carry = 0
        andAB = a & b
        orAB = a | b
        #print "orAB:", orAB
        result = 0
        for i in xrange(10):    #the size of integer in python is 24Bytes?
            one = 1 << i
            #print("result:{0}, carry:{1}, one:{2}".format(result, carry, one))
            #一定要注意：按位运算符(&,|,!)优先级高于逻辑运算符（and, or)，但都低于==和!=;逻辑运算符not的优先级很高，高于前述所有运算符;赋值运算符=的优先级很低，低于前述所有的运算符.
            if (andAB & one) == one:  #(1, 1)
                if carry == 1:
                    result |= one
                carry = 1
            elif (orAB & one) == one: #(1, 0) or (0, 1)
                #print "in or"
                if carry == 0:
                    result |= one
            else: #(0, 0)
                if carry == 1:
                    result |= one
                    carry = 0
        return int(result)

    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        """
        Main Idea:
        If x and y don’t have set bits at same position(s), then bitwise XOR (^) of x and y gives the sum of x and y.
        To incorporate common set bits also, bitwise AND (&) is used. Bitwise AND of x and y gives all carry bits.
        We calculate (x & y) << 1 and add it to x ^ y to get the required result.
        """
        """
        由于Python没有无符号右移操作，并且当左移操作的结果超过最大整数范围时，会自动将int类型转换为long类型，因此需要对上述代码进行调整。
        References: 
        1. http://bookshadow.com/weblog/2016/06/30/leetcode-sum-of-two-integers/
        2. http://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
        """
        MAX_INT = 0x7FFFFFFF
        MIN_INT = 0x80000000
        MASK = 0x100000000
        print MASK
        while b != 0:
            carry = (a & b) % MASK
            a = (a ^ b) % MASK
            b = (carry << 1) % MASK
        return a if a <= MAX_INT else ~((a % MIN_INT) ^ MAX_INT)
        #return a if a <= MAX_INT else (a % MASK) #NO

def main():
    sol = Solution()
    #Y
    a = 1
    b = 2
    print "sum of {0} and {1} is {2}".format(a, b, sol.getSum(a, b))

    #Y
    a = 4
    b = -3
    print "sum of {0} and {1} is {2}".format(a, b, sol.getSum(a, b))

    #N
    a = int(-1)
    b = int(-2)
    print "sum of {0} and {1} is {2}".format(a, b, sol.getSum(a, b))

    #N
    a = -4
    b = 3
    print "sum of {0} and {1} is {2}".format(a, b, sol.getSum(a, b))

if __name__ == "__main__":
    main()