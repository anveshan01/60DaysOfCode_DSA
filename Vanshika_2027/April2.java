//https://leetcode.com/problems/daily-temperatures/
class Solution {
    public int[] dailyTemperatures(int[] temps) {
        int n = temps.length;
        int[] ans = new int[n];
        Stack<Integer> s = new Stack<>();

        for(int i=0; i<n;i++){
            while(!s.isEmpty() && temps[i]>temps[s.peek()]){
                int prev = s.pop();
                ans[prev] = i-prev;
            }
            s.push(i);
        }
        return ans;
    }
}

//https://leetcode.com/problems/container-with-most-water/
class Solution {
    public int maxArea(int[] height) {
        int max =0;
        int l =0;
        int r = height.length-1;

        while(l<r){
            int curr = (r-l)*Math.min(height[l],height[r]);
            max = Math.max(max,curr);
            if(height[l]<height[r]){
                l++;
            }else{
                r--;
            }
        }
        return max;
    }
}