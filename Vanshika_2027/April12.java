//https://leetcode.com/problems/swap-nodes-in-pairs/
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
    public ListNode swapPairs(ListNode head) {
        ListNode temp = new ListNode(0);
        temp.next = head;
        ListNode prev = temp;

        while(head!=null && head.next!=null){
            ListNode f = head, s = head.next;
            prev.next = s;
            f.next = s.next;
            s.next = f;
            prev = f;
            head = f.next;
        }
        return temp.next;
    }
}