https://leetcode.com/problems/odd-even-linked-list
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
    public ListNode oddEvenList(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode odd = head;
        ListNode even = head.next;
        ListNode evenH = even;
        while(even!=null && even.next!=null){
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }
        odd.next = evenH;
        return head;
    }
}

//https://leetcode.com/problems/longest-nice-subarray
class Solution {
    public int longestNiceSubarray(int[] nums) {
        int max =0;
        int l =0;
        int bmask =0;
        for(int r =0; r<nums.length;r++){
            while((bmask & nums[r]) != 0){
                bmask ^= nums[l];
                l++;
            }
            bmask |= nums[r];
            max = Math.max(max, r-l+1);
        }
        return max;
    }
}