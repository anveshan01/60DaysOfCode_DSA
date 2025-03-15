# 160. Intersection of Two Linked Lists
#  date 15-3-25

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        h1=headA
        h2=headB
        l1=[]
        l2=[]

        if h1 ==None or h2==None:
            return None


        while h1:
            l1.append(h1)
            h1=h1.next
        while h2:
            l2.append(h2)
            h2=h2.next
        
        i, j = len(l1) - 1, len(l2) - 1
        intersection = None

        while i >= 0 and j >= 0 and l1[i] == l2[j]:
            intersection = l1[i]
            i -= 1
            j -= 1
        return intersection