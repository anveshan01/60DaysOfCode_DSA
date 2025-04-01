//https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/
class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        long[] preSum = new long[n+1];
        for(int i=0;i<n;i++){
            preSum[i+1] = preSum[i] + nums[i];
        }

        Deque<Integer> dq = new LinkedList<>();
        int min = Integer.MAX_VALUE;

        for(int i=0; i<=n;i++){
            while(!dq.isEmpty() && (preSum[i]-preSum[dq.peekFirst()])>=k){
                min = Math.min(min, i-dq.removeFirst());
            }
            while(!dq.isEmpty() && preSum[i]<=preSum[dq.peekLast()]){
                dq.removeLast();
            }
            dq.addLast(i);
        }
        return (min==Integer.MAX_VALUE) ? -1 : min;
    }
}