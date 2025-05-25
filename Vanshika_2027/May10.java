// https://leetcode.com/problems/reverse-linked-list-ii/submissions
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(left==right) return head;

        ListNode temp = new ListNode();
        temp.next = head;
        ListNode prev = temp;
        for(int i=1; i<left; i++){
            prev=prev.next;
        }
        ListNode curr = prev.next;
        ListNode next = curr.next;
        for(int i=0; i<right-left; i++){
            curr.next=next.next;
            next.next=prev.next;
            prev.next=next;
            next=curr.next;
        }
        return temp.next;

    }
}