class Solution {
    int sumdigit(int k){
        int sum=0;
        while(k>0){
            int res=k%10;
            sum+=res;
            k=k/10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        int count=0;
        unordered_map<int,int>mpp;
        for(int i=1;i<=n;i++){
            int sum=sumdigit(i);
            mpp[sum]++;
        }
        int maxfreq=0;
        for(auto it:mpp){
          maxfreq=max(maxfreq,it.second);
        }
        for(auto it:mpp){
            if(it.second==maxfreq){
                count++;
            }
        }
        return count;
    }
};