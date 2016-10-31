#!/usr/bin/python2.7
# FileName: num071.py
# Author: lxw
# Date: 2015-07-03

"""
Num 019: 
Source: 

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
"""

# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, x):
         self.value = x
         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        nodeFast = head
        nodeSlow = head
        while n != 0:
            nodeFast = nodeFast.next
            n -= 1

        if not nodeFast:
            nodeFast = head
            head = head.next
            del nodeFast
            return head

        while nodeFast.next:
            nodeFast = nodeFast.next
            nodeSlow = nodeSlow.next

        nodeSlow.next = nodeSlow.next.next
        del nodeFast
        return head

    def showList(self, head):
        temp = head
        while temp:
            print temp.value, "\t",
            temp = temp.next
        print ""

if __name__ == '__main__':
    sol = Solution()
    node1 = ListNode(1)
    node2 = ListNode(2)
    node3 = ListNode(3)
    node4 = ListNode(4)
    node5 = ListNode(5)
    head = node1
    node1.next = node2
    node2.next = node3
    node3.next = node4
    node4.next = node5
    sol.showList(head)
    head = sol.removeNthFromEnd(head, 5)
    sol.showList(head)

