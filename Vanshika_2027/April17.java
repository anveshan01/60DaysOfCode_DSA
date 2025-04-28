https://leetcode.com/problems/largest-rectangle-in-histogram/description/
class Solution {
    public int largestRectangleArea(int[] arr) {
        int n = arr.length;
        int[] nsr = new int[n];
        int[] nsl = new int[n];
        Stack<Integer> s = new Stack<>();
        //nsr[j]
        for(int i=n-1;i>=0;i--){
            while(!s.isEmpty() && arr[s.peek()]>=arr[i]){
                s.pop();
            }
            if(s.isEmpty()){
                nsr[i] = n;
            }else{
                nsr[i]=s.peek();
            }
            s.push(i);
        }
        s.clear();
        //nsl(i)
        for(int i=0;i<n;i++){
            while(!s.isEmpty() && arr[s.peek()]>=arr[i]){
                s.pop();
            }
            if(s.isEmpty()){
                nsl[i] = -1;
            }else{
                nsl[i]=s.peek();
            }
            s.push(i);
        }
        for(int i=0; i<n;i++){
            arr[i] = arr[i] * (nsr[i]-nsl[i]-1);
        }
        //maxArea
        int max = arr[0];
        for(int i=1;i< n;i++){
            if(max<=arr[i]){
                max=arr[i];
            }
        }
        return max;
    }
}