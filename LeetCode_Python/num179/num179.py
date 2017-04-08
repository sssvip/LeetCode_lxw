#!/usr/bin/python2.7
# FileName: num179.py
# Author: lxw
# Date: 2017-04-08

"""
Num num179: Largest Number
Source: https://leetcode.com/problems/largest-number/

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
"""

class Solution:
    # @param {integer[]} nums
    # @return {string}

    def getBinStr(self, numList):
        """
        Bubble sort.
        """
        #Time: O(n^2)
        length = len(numList)
        if length == 0:
            return ""

        while 1:
            swapFlag = False
            for index in xrange(length-1):
                if numList[index] + numList[index + 1] < numList[index+1] + numList[index]:
                    swapFlag = True
                    temp = numList[index]
                    numList[index] = numList[index+1]
                    numList[index+1] = temp
            if not swapFlag:
                break
        return "".join(numList)

    #Method 1
    def largestNumber1(self, nums):
        """
        Time: O(n^2). 48 ms
        based on bin sort and bubble sort.
        """
        largest = []
        length = len(nums)
        if length < 1:
            return ""
        elif length == 1:
            return str(nums[0])
        
        strNums = []
        for i in range(10): #Time: O(1). Space: O(1)
            strNums.append([])
            
        for num in nums: #Time: O(n). Space: O(n)
            num = str(num)
            strNums[int(num[0])].append(num)
        
        for numList in strNums: #Time: O(nlogn).
            numList.sort(reverse=True)
        
        for index in range(9, -1, -1):
            largest.append(self.getBinStr(strNums[index]))

        result = "".join(largest)
        return "0" if result.startswith("0") else result

    #Method 2
    def largestNumber(self, nums):
        """
        Time: O(nlogn).  48ms
        based on quick sort.
        """
        length = len(nums)
        if length < 1:
            return ""
        elif length == 1:
            return str(nums[0])

        strNums = [str(num) for num in nums]
        strNums.sort(cmp=lambda x,y : cmp(y+x, x+y))
        #strNums.sort(cmp=lambda x,y : cmp(x+y, y+x)) #NO
        result = "".join(strNums)
        return "0" if result.startswith("0") else result


if __name__ == "__main__":
    sol = Solution()
    numbers = [10, 2]
    print sol.largestNumber(numbers)
    numbers = [121, 12, 10, 2, 3223, 232, 1, 4, 5, 87]
    print sol.largestNumber(numbers)
    numbers = [0, 0]
    print sol.largestNumber(numbers)
