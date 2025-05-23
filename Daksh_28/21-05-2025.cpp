// LeetCode 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int a : asteroids){
            if(a > 0){
                st.push(a);
            }
            else{
                while(!st.empty() && st.top() > 0 && st.top() < -a){
                    st.pop();
                }
                if(st.empty() || st.top() < 0){
                    st.push(a);
                }
                if(!st.empty() && st.top() == -a){
                    st.pop();
                }
            }
        }
        vector<int> res(st.size());
        int n = st.size() - 1;

        while(!st.empty()){
            res[n--] = st.top();
            st.pop();
        }
        return res;
    }
};
// T.C : O(n)
// S.C : O(n)