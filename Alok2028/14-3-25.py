
# problem statement :: 141. Linked List Cycle 
# date 14-3-25

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        temp=head
        nodeli=[]
        while True:
            if head==None:
                return False
            elif temp.next==None :
                return False
            elif temp in nodeli:
                return True
            nodeli.append(temp)
            temp=temp.next

        #if the node aleready exists in the list nodeli then we can say that it loops
        # in a linked list no node can point to 2 other nodes hence loop is done at from the last element therefore if it point to None then no loop happens
        