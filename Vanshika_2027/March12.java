//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
class Solution {
    public boolean search(int[] nums, int target) {
        int n = nums.length;
        int s =0, e=n-1;
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m] == target) return true;
            if(nums[s]==nums[m] && nums[m] == nums[e]){
                s++;
                e--;
                continue;
            }
            if(nums[s] <= nums[m]){//left-half sorted
                if(nums[s]<=target && target<=nums[m]){
                    e=m-1;
                }else{
                    s=m+1;
                }
            }else{
                if(nums[m]<=target && target<=nums[e]){
                    s=m+1;
                }else{
                    e=m-1;
                }
            }
        }
        return false;
    }
}

//https://leetcode.com/problems/valid-parentheses/
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (char i : s.toCharArray()) {
            if (i == '(')
                stack.push(')');
            else if (i == '[')
                stack.push(']');
            else if (i == '{')
                stack.push('}');
            else if (stack.isEmpty() || stack.pop() != i)
                return false;
        }
        return stack.isEmpty();
    }
}

//https://leetcode.com/problems/insert-interval/
class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        ArrayList<int[]> res = new ArrayList<>();
        int i=0, n=intervals.length;
        //left non-overlap
        while(i<n && intervals[i][1]<newInterval[0]){
            res.add(intervals[i]);
            i++;
        }
        //overlap
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0] = Math.min(newInterval[0],intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1],intervals[i][1]);
            i++;
        }
        res.add(newInterval);
        //right non-overlap
        while(i<n){
            res.add(intervals[i]);
            i++;
        }
        return res.toArray(new int[res.size()][]);
    }
}