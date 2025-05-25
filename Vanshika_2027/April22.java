// https://leetcode.com/problems/asteroid-collision/description/

class Solution {
    public int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> st = new Stack<>();
        for(int ast:asteroids){
            if(ast>0) st.push(ast);
            else{
                while(!st.isEmpty() && st.peek()<Math.abs(ast)){
                    st.pop();
                }
                if(!st.isEmpty() && st.peek()==Math.abs(ast)){
                    st.pop();
                }else if(st.isEmpty() || st.peek()<0){
                    st.push(ast);
                }
            }
        }
        int[] res = new int[st.size()];
        for(int i = res.length-1;i>=0;i--){
            res[i] = st.pop();
        }
        return res;
    }
}