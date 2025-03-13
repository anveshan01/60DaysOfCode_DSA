//https://leetcode.com/problems/min-stack/submissions/1572672361/
class MinStack {
    private Stack<Long> s;
    private long min;

    public MinStack() {
        s = new Stack<>();
        min = Long.MAX_VALUE;
    }

    public void push(int val) {
        long x = val;
        if(s.isEmpty()){
            min = x;
            s.push(x);
        }else{
            if(x>=min){
                s.push(x);
            }else{
                s.push((2*x) - min);
                min = x;
            }
        }
    }

    public void pop() {
        if(s.isEmpty()) return;
        long top = s.pop();
        if(top<min){
            min = (2*min) - top;
        }
    }

    public int top() {
        long top = s.peek();
        if(top<min){
            return (int)min;
        }
        return (int)top;
    }

    public int getMin() {
        return (int)min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */