//https://leetcode.com/problems/gray-code/
class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> res =new ArrayList<>();
        int total= 1<<n;  //2^n

        for(int i=0; i<total;i++) {
            res.add(i^(i>>1));
        }
        return res;
    }
}