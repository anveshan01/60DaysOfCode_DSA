# 19. Remove Nth Node From End of List
# date 20-3-25

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        slow,end=head,head
        if head==None:
            return None
        elif head.next==None and n==1:
            return None
        else:
            len=1
            for _ in range (0,n):
                if end.next==None:
                    continue
                else:
                    end=end.next
                    len+=1
            

            while end.next!=None :
                # taking end to end
                end=end.next
                slow=slow.next
                len+=1
            if len==n:
                return head.next
            else:
                slow.next=slow.next.next
                return head

