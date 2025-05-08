class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans=~n;
        int mask=0;
        while(n!=0){
            n=(n>>1);
            mask=(mask<<1);
            mask=mask|1;
        }
        ans=ans&mask;
        return ans;

    }
};
