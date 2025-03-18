# 234. Palindrome Linked List
# date : 18-3-25

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: bool
        """
        if not head or not head.next:
             return True  

        cen, end = head, head
        while end and end.next:
            cen = cen.next
            end = end.next.next

        def reverse(node):
            prev, curr = None, node
            while curr:
                nxt = curr.next
                curr.next = prev
                prev, curr = curr, nxt
            return prev  

        right = reverse(cen)
        left = head

        while right:
            if left.val != right.val:
                return False
            left, right = left.next, right.next

        return True