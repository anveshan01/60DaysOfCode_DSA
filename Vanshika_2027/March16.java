//https://leetcode.com/problems/single-element-in-a-sorted-array/
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n=nums.length;
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int s=1, e=n-2;
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m]!=nums[m+1] && nums[m]!=nums[m-1]){
                return nums[m];
            }else if((nums[m]==nums[m-1] && m%2==1) || (nums[m]==nums[m+1] && m%2==0) ){
                s=m+1;
            }else{
                e=m-1;
            }
        }
        return -1;
    }
}

//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
    private static final String[] KeyPad = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        if(digits.isEmpty()) return ans;
        combinations(0,ans, new StringBuilder(), digits);
        return ans;
    }
    public static void combinations(int ind, List<String> ans, StringBuilder curr, String digits){
        if(ind==digits.length()){
            ans.add(curr.toString());
            return;
        }
        int num = digits.charAt(ind)-'0';
        String text = KeyPad[num];
        for(char ch : text.toCharArray()){
            curr.append(ch);
            combinations(ind+1,ans, curr, digits);
            curr.deleteCharAt(curr.length()-1);
        }
    }
}