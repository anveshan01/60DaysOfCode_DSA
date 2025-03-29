class Solution {
public:
    int mySqrt(int x) {
        int st=0,end=x;
        while(st<=end){
            long long mid=st+(end-st)/2;
            if(mid*mid>x) end=mid-1;
            else if(mid*mid<x) st=mid+1;
            else return mid;
        }
        return end;
        
    }
    
};
