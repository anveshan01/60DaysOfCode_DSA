//fibonacci NUMBER LEETCODE
class Solution {
public:
    int fib(int n) {
        int a=0;
        int b=1;
        if(n==0){
            return 0;
            }
        if(n==1) return 1;
        for(int i=0;i<n;i++){
            int third=a+b;
            a=b;
            b=third;
        }
        return a;
    }
};

class Solution {
public:
    int fib(int n) {
        int a=0;
        int b=1;
        if(n==0){
            return 0;
            }
        if(n==1) return 1;
        return fib(n-2)+fib(n-1);
    }
};
