#!/usr/bin/python2.7
# FileName: num002.py
# Author: lxw
# Time: 2015-04-30

"""
Num 002: Add Two Numbers.
Source: https://leetcode.com/problems/add-two-numbers/

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
"""

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def __init__(self):
        pass

    def addTwoNumbers(self, l1, l2):
        """
        l1: ListNode, l2: ListNode
        return ListNode
        """
        retList = ListNode(0)
        curPosition = retList
        carry = 0
        while 1:
            if l1 and l2:
                value = l1.val + l2.val + carry
                carry = value / 10
                curPosition.next = ListNode(value % 10)
                curPosition = curPosition.next
                l1 = l1.next
                l2 = l2.next
            else:
                break

        while 1:
            if l1:
                value = l1.val + carry
                carry = value / 10
                curPosition.next = ListNode(value % 10)
                curPosition = curPosition.next
                l1 = l1.next
            else:
                break

        while 1:
            if l2:
                value = l2.val + carry
                carry = value / 10
                curPosition.next = ListNode(value % 10)
                curPosition = curPosition.next
                l2 = l2.next
            else:
                break

        if carry:
            curPosition.next = ListNode(carry)

        return retList.next


def showList(listNode):
    while 1:
        if not listNode:
            break
        print listNode.val, ",",
        listNode = listNode.next


def main():
    s = Solution()
    l1 = ListNode(0)
    curPosition = l1
    for item in xrange(1, 10):
        curPosition.next = ListNode(item)
        curPosition = curPosition.next

    l2 = ListNode(0)
    curPosition = l2
    for item in xrange(9, 1, -1):
        curPosition.next = ListNode(item)
        curPosition = curPosition.next

    print "l1: "
    showList(l1.next)
    print ""
    print "l2: "
    showList(l2.next)
    print ""

    print "Result List: "
    showList(s.addTwoNumbers(l1.next, l2.next))
    print ""

    print "l1: "
    showList(l1.next)
    print ""
    print "l2: "
    showList(l2.next)
    print ""

if __name__ == '__main__':
    main()
else:
    print("Being imported as a module.")
