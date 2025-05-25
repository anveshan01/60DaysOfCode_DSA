// https://leetcode.com/problems/permutations-ii
class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> ds = new ArrayList<>();
        boolean[] freq = new boolean[nums.length];
        permute(nums,ans,ds,freq);
        return ans;
    }
    static void permute(int[] nums, List<List<Integer>> ans,List<Integer> ds,boolean[] freq){
        //base case
        int n=nums.length;
        if(ds.size() == n){
            ans.add(new ArrayList<>(ds));
            return;
        }
        //backtracking
        for(int i=0; i<n; i++){
            //duplication
            if(i>0 && nums[i]==nums[i-1] && !freq[i-1]){
                continue;
            }
            if(!freq[i]){
                freq[i] = true;
                ds.add(nums[i]);
                permute(nums,ans,ds,freq);
                freq[i]=false;
                ds.removeLast();
            }
        }
    }

}