//https://leetcode.com/problems/min-stack/submissions/1572672361/
class MinStack {
    private Stack<Long> s;
    private long min;

    public MinStack() {
        s = new Stack<>();
        min = Long.MAX_VALUE;
    }

    public void push(int val) {
        long x = val;
        if(s.isEmpty()){
            min = x;
            s.push(x);
        }else{
            if(x>=min){
                s.push(x);
            }else{
                s.push((2*x) - min);
                min = x;
            }
        }
    }

    public void pop() {
        if(s.isEmpty()) return;
        long top = s.pop();
        if(top<min){
            min = (2*min) - top;
        }
    }

    public int top() {
        long top = s.peek();
        if(top<min){
            return (int)min;
        }
        return (int)top;
    }

    public int getMin() {
        return (int)min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
    public int findMin(int[] nums) {
        int s =0, e = nums.length-1;
        int min = Integer.MAX_VALUE;
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[s]<=nums[e]){
                min = Math.min(min,nums[s]);
                break;
            }
            if(nums[s]<=nums[m]){
                min = Math.min(min,nums[s]);
                s=m+1;
            }else{
                min = Math.min(min,nums[m]);
                e=m-1;
            }
        }
        return min;
    }
}

//https://leetcode.com/problems/merge-intervals/submissions/1573145202/
class Solution {
    public int[][] merge(int[][] intervals) {
        int n = intervals.length;
        Arrays.sort(intervals, new Comparator<int[]>(){
            public int compare(int[] a, int[] b){
                return a[0]-b[0];
            }
        });
        List<int[]> ans = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            if(ans.isEmpty() || intervals[i][0] > ans.get(ans.size() - 1)[1]) {
                ans.add(intervals[i]);
            } else {
                ans.get(ans.size() - 1)[1] = Math.max(ans.get(ans.size() - 1)[1], intervals[i][1]);
            }
        }
        return ans.toArray(new int[ans.size()][]);
    }
}