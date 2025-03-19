//https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i
class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        if(n<3) return -1;
        int count =0;
        for(int i =0; i<n-2;i++){
            if(nums[i]==0){
                nums[i]^=1;
                nums[i+1]^=1;
                nums[i+2]^=1;
                count++;
            }
        }
        if(nums[n-1]==0 || nums[n-2]==0) return -1;
        return count;
    }
}

//https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/
class Solution {
    public String findLexSmallestString(String s, int a, int b) {
        Queue<String> q = new LinkedList<>();
        HashSet<String> vSet = new HashSet<>();
        String min = s;
        q.add(s);
        vSet.add(s);
        while(!q.isEmpty()){
            String curr = q.poll();
            if(curr.compareTo(min)<0){
                min =curr;
            }
            char[] ch = curr.toCharArray();
            for(int i =1; i<ch.length;i+=2){
                ch[i] = (char)((((ch[i]-'0')+a)%10)+'0');
            }
            String added = new String(ch);
            if(!vSet.contains(added)){
                vSet.add(added);
                q.add(added);
            }
            String rotated = curr.substring(s.length()-b) + curr.substring(0,s.length()-b);
            if(!vSet.contains(rotated)){
                vSet.add(rotated);
                q.add(rotated);
            }
        }
        return min;
    }
}