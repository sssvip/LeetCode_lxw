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
        curPosition = resultList
        carry = 0
        l1 = l1.next
        l2 = l2.next
        while 1:
            if l1 and l2:
                value = l1.value + l2.value + carry
                carry = value / 10
                value = value % 10
                curPosition.next = ListNode(value)
                curPosition = curPosition.next
                l1 = l1.next
                l2 = l2.next
            else:
                break

        while 1:
            if l1:
                value = l1.value + carry
                carry = value / 10
                value = value % 10
                curPosition.next = ListNode(value)
                curPosition = curPosition.next
                l1 = l1.next
            else:
                break
        while 1:
            if l2:
                value = l2.value + carry
                carry = value / 10
                value = value % 10
                curPosition.next = ListNode(value)
                curPosition = curPosition.next
                l2 = l2.next
            else:
                break

        if carry:
            curPosition.next = ListNode(carry)
            curPosition = curPosition.next

        return resultList

def showList(listNode):
    if listNode:
        listNode = listNode.next

    while 1:
        if not listNode:
            break
        print listNode.value, ",",
        listNode = listNode.next


def main():
    s = Solution()
    l1 = ListNode(0)    # The sentinel node
    curPosition = l1
    for item in xrange(1, 10):
        ln = ListNode(item)
        curPosition.next = ln
        curPosition = ln

    l2 = ListNode(0)    # The sentinel node
    curPosition = l2
    for item in xrange(9, 1, -1):
        ln = ListNode(item)
        curPosition.next = ln
        curPosition = ln

    print "l1: "
    showList(l1)
    print ""
    print "l2: "
    showList(l2)
    print ""

    resultList = s.addTwoNumbers(l1, l2)
    print "Result List: "
    showList(resultList)
    print ""

    print "l1: "
    showList(l1)
    print ""
    print "l2: "
    showList(l2)
    print ""

if __name__ == '__main__':
    main()
else:
    print("Being imported as a module.")
