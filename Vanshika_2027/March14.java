//https://www.geeksforgeeks.org/problems/rotation4723/0
class Solution {
    public int findKRotation(List<Integer> arr) {
        int s =0, e = arr.size()-1;
        int ans = Integer.MAX_VALUE;
        int k =-1;
        while(s<e){
            int m = s+(e-s)/2;
            if(arr.get(m)>arr.get(e)){
                s=m+1;
            }else{
                e=m;
            }
        }
        return s;
    }
}