//tribonacci series leetcode
class Solution {
public:
    int tribonacci(int n) {
        // int first=0,second=1,third=1;
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }

class Solution {
public:
    int tribonacci(int n) {
        long long a=0,b=1,c=1;
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        
        for(int i=3;i<=n;i++){
            long long third=a+b+c;
            a=b;
            b=c;
            c=third;
        }
        return c;
    }
};
