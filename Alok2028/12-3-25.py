# date: 12-03-25

# Leetcode problem number :: 206. Reverse Linked List 

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if  not head:
            return head

        else :
            prev=None
            while head:
                cur=head
                future=head.next
                cur.next=prev
                prev=head
                head=future
        
        return prev