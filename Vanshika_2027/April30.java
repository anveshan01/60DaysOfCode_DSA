// https://leetcode.com/problems/happy-number/
class Solution {
    public boolean isHappy(int n) {
        int s = n;
        int f = n;

        do{
            s = squareOf(s);
            f = squareOf(squareOf(f));
        }while(s!=f);

        if(s==1) return true;
        return false;
    }

    static int squareOf(int num){
        int ans = 0;
        while(num>0){
            int rem = num%10;
            ans += rem*rem;
            num/=10;
        }
        return ans;
    }
}