//https://leetcode.com/problems/combination-sum/
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        combination(0, candidates, target, ans, new ArrayList<>());
        return ans;
    }
    public void combination(int i, int[] arr, int t, List<List<Integer>> ans, List<Integer> ds){
        //base case
        if(i==arr.length){
            if(t==0){
                ans.add(new ArrayList<>(ds));
            }
            return;
        }
        //picking
        if(arr[i]<=t){
            ds.add(arr[i]);
            combination(i, arr, t-arr[i], ans, ds);
            ds.remove(ds.size()-1);
        }
        //notpicking
        combination(i+1, arr, t, ans, ds);
    }
}

//https://leetcode.com/problems/get-equal-substrings-within-budget
class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length();
        int left = 0, right =0;
        int cost=0, max=0;
        while(right<n){
            cost+=Math.abs(s.charAt(right)- t.charAt(right));
            while(cost> maxCost){
                cost -= Math.abs(s.charAt(left) - t.charAt(left));
                left++;
            }
            max
                    = Math.max(max
                    , right -left+1);
            right++;
        }
        return max
                ;
    }
}