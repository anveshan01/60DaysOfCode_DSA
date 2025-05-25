// https://leetcode.com/problems/minimum-length-of-string-after-operations
class Solution {
    public int minimumLength(String s) {
        HashMap<Character,Integer> count = new HashMap<>();

        for(char ch : s.toCharArray()){
            count.put(ch,(count.getOrDefault(ch,0)+1));
        }
        //[(a,3),(b,4),(c,2)]
        int diff =0;
        for(int val: count.values()){
            while(val>=3){
                diff+=2;//d=2+2
                val-=2;//(a,1),(b,2),(c,2)
            }
        }
        return s.length()-diff;
    }
}