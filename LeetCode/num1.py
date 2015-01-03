#FileName: E:/lxw/Documents/Program/Python/LeetCode/num1.py
#coding: utf-8
#Author: lxw
#Date: 2014-12-31
#Usage: LeetCode num 1. 
#alt + /

class Solution:
    # @return a tuple, (index1, index2)
    '''
    def twoSum(self, num, target):
        index0 = 0
        index1 = -1 
        for item in num:
            index0 += 1
            other = target - item
            try:
                index1 = num[index0:].index(other)
                index1 += index0 + 1
            except ValueError:
                continue
            else:
                break
        return index0, index1
    '''

    def twoSum(self, num, target):
        length = len(num)
        dic = {}
        for i in xrange(length):
            dic[num[i]] = i
        index0 = -1
        index1 = -1 
        for key in xrange(length):  #not "for key in dic.values():" 
            other = target - num[key]
            index1 = dic.get(other)
            #[1, 2, 3, 4], 4:   2,2 is not the EXPECTED answer.
            if index1 and index1 != key:
                index0 = key + 1
                index1 += 1
                break

        return index0, index1


def main():
    sol = Solution()
    num = []
    for i in xrange(1000):
        num.append(i)
    num = [0, 4, 3, 0, 0]
    #print sol.twoSum(num, 1900)
    print sol.twoSum(num, 7)

main()