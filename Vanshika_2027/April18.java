//https://www.interviewbit.com/problems/nearest-smaller-element/
public class Solution {
    public ArrayList<Integer> prevSmaller(ArrayList<Integer> A) {
        ArrayList<Integer> ans = new ArrayList<>();
        Stack<Integer> s = new Stack<>();

        for (int i = 0; i < A.size(); i++) {
            while (!s.isEmpty() && s.peek() >= A.get(i)) {
                s.pop();
            }
            if (s.isEmpty()) {
                ans.add(-1);
            } else {
                ans.add(s.peek());
            }
            s.push(A.get(i));
        }
        return ans;
    }
}