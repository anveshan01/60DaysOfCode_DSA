//https://leetcode.com/problems/next-greater-element-i/
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        HashMap<Integer, Integer> map = new HashMap<>();
        Stack<Integer> st = new Stack<>();
        for(int num : nums2){
            while(!st.isEmpty() && num>st.peek()){
                map.put(st.pop(),num);
            }
            st.push(num);
        }
        while(!st.isEmpty()){
            map.put(st.pop(),-1);
        }
        int[] ans = new int[nums1.length];
        for(int i=0;i<ans.length;i++){
            ans[i] = map.getOrDefault(nums1[i],-1);
        }
        return ans;
    }
}

//https://leetcode.com/problems/next-greater-element-ii/
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] nge = new int[nums.length];
        Stack<Integer> st = new Stack<>();
        for(int i=2*n-1; i>=0;i--){
            while(!st.isEmpty() && st.peek()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                nge[i] = st.isEmpty() ? -1 : st.peek();
            }
            st.push(nums[i%n]);
        }
        return nge;
    }
}

// https://leetcode.com/problems/copy-list-with-random-pointer/description/
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head==null) return null;

        Node curr = head;
        while(curr!=null){
            Node temp = curr.next;
            curr.next = new Node(curr.val);
            curr.next.next = temp;
            curr = temp;
        }
        curr=head;

        while(curr!=null){
            if(curr.next!=null) curr.next.random = curr.random!=null? curr.random.next : null;
            curr = curr.next.next;
        }

        Node og = head, copy = head.next;
        Node temp = copy;
        while(og!=null){
            og.next = og.next.next;
            copy.next = (copy.next != null) ? copy.next.next : null;
            og = og.next;
            copy = copy.next;
        }
        return temp;

    }
}

// https://leetcode.com/problems/find-the-largest-almost-missing-integer/
class Solution {
    public int largestInteger(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int num : nums){
            map.put(num, map.getOrDefault(num,0)+1);
        }
        int max =-1;
        //case1:
        if(k==1){
            for(int num : nums){
                if(map.get(num)==1){
                    max = Math.max(max,num);
                }
            }
            return max;
        }else if(k==n){
            for(int num : nums){
                max = Math.max(max,num);
            }
            return max;
        }else{
            boolean first = map.get(nums[0]) ==1;
            boolean last = map.get(nums[n-1]) ==1;

            if(first && last){
                return Math.max(nums[0],nums[n-1]);
            }else if(first){
                return nums[0];
            }else if(last){
                return nums[n-1];
            }else{
                return -1;
            }
        }
    }
}