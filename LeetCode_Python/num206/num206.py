#!/usr/bin/python2.7
# FileName: num206.py
# Author: lxw
# Date: 2015-05-05

"""
Num 206: Reverse Linked List.
Source: https://leetcode.com/problems/reverse-linked-list/

Reverse a singly linked list.
Hint:
    A linked list can be reversed either iteratively or recursively. Could you implement both?
"""
import random

class ListNode:
    """
    Definition for singly-linked list Node.
    """
    def __init__(self, x):
        self.val = x
        self.next = None


class List:
    """
    Definition for singly-linked list.
    """
    def __init__(self, length):
        self.head = ListNode(0)
        cur = self.head
        for index in xrange(length):
            node = ListNode(random.randint(1, 100))
            cur.next = node
            cur = cur.next
        self.head = self.head.next


class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList_iterative(self, head):
        """
        Iteratively.
        """
        if not head:
            return head
        behind = head
        head = head.next
        behind.next = None
        while head:
            temp = head.next
            head.next = behind
            behind = head
            head = temp
        head = behind
        return behind

    def reverseList_recursive(self, head):
        """
        Recursively.
        """
        if head.next:
            self.reverseList_recursive(head.next).next = head
        else:
            self.newHead = head
        return head

    def reverseList(self, head):
        """
        Recursively.
        """
        if head:
            self.reverseList_recursive(head).next = None
            return self.newHead
        else:
            return head

    def showList(self, head):
        cur = head
        while cur:
            print cur.val,
            cur = cur.next
        print ""    #newline

def main():
    ll = List(10)
    sol = Solution()
    sol.showList(ll.head)
    sol.showList(sol.reverseList(ll.head))


if __name__ == '__main__':
    main()
else:
    print("Being imported as a module.")
