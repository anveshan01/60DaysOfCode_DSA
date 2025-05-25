//https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> minH = new PriorityQueue<>();

        for(int num : nums){
            minH.add(num);
            if(minH.size()>k){
                minH.poll();
            }
        }

        return minH.peek();
    }
}