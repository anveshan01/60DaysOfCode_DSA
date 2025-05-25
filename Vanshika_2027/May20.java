//https://leetcode.com/problems/permutations/
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        permutations(0, nums, ans);
        return ans;
    }
    static void permutations(int ind, int[] nums, List<List<Integer>> ans){
        //base case
        int n = nums.length;
        if(ind == n){
            List<Integer> ds = new ArrayList<>();
            for(int num :nums){
                ds.add(num);
            }
            ans.add(new ArrayList<>(ds));
            return;
        }
        //backtracking
        for(int i = ind; i<n;i++){
            swap(i,ind,nums);
            permutations(ind+1,nums,ans);
            swap(i,ind,nums);
        }
    }
    static void swap(int i, int j, int[] nums){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
}