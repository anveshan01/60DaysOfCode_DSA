//https://leetcode.com/problems/gas-station/
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int n =gas.length;
        int total =0;
        int curr =0;
        int start = 0;
        for(int i=0;i<n;i++){
            int net = gas[i]-cost[i];
            total+=net;
            curr += net;
            if(curr<0){
                start=i+1;
                curr=0;
            }
        }
        return total>=0 ? start : -1;
    }
}

//https://www.naukri.com/code360/problems/sort-linked-list-of-0s-1s-2s_1071937
/****************************************************************

 Following is the class structure of the Node class:

 class Node {
 public int data;
 public Node next;

 Node()
 {
 this.data = 0;
 this.next = null;
 }

 Node(int data)
 {
 this.data = data;
 this.next = null;
 }

 Node(int data, Node next)
 {
 this.data = data;
 this.next = next;
 }
 }

 *****************************************************************/

public class Solution
{
    public static Node sortList(Node head) {
        if(head==null || head.next == null) return head;
        Node zeroH = new Node(-1);
        Node zero = zeroH;
        Node oneH = new Node(-1);
        Node one = oneH;
        Node twoH = new Node(-1);
        Node two = twoH;
        Node temp = head;

        while(temp!=null){
            if(temp.data==0){
                zero.next = temp;
                zero = zero.next;
            }else if(temp.data==1){
                one.next = temp;
                one = one.next;
            }else{
                two.next = temp;
                two = two.next;
            }
            temp = temp.next;
        }
        zero.next = (oneH!=null) ? oneH.next : twoH.next;
        one.next = twoH.next;
        two.next = null;
        return zeroH.next;
    }
}