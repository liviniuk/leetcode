# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        if head.next is None:
            return None
        node = head
        l = 1
        while node.next is not None:
            node = node.next
            l += 1
        if l == n:
            return head.next
        node = head
        for i in range(l - 1 - n):
            node = node.next
        node.next = node.next.next
        return head
