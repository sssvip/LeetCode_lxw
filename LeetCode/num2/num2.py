#!/usr/bin/python2.7
#File: num2.py
#Author: lxw
#Time: 2015-04-30
#Usage: Num 2: Add Two Numbers.

class ListNode(object):
    def __init__(self, value):
        self.value = value
        self.next = None


class Solution(object):
    def __init__(self):
        pass

    def addTwoNumbers(self, l1, l2):
        """
        l1: ListNode, l2: ListNode
        return ListNode
        """
        resultList = ListNode(0)    # The sentinel node
        carry = 0
        while 1:
            if l1 and l2:
                value = l1.value + l2.value + carry
                carry = value / 10
                carry = value % 10


def main():
    s = Solution()
    s.addTwoNumbers()


if __name__ == '__main__':
    main()
else:
    print("Being imported as a module.")

