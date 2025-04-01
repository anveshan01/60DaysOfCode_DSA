class Solution {
    int count(int num){
         if (num <= 1) return 0;
        int count = 0;
        if (num % 2 == 0) {
            count++;
            while (num % 2 == 0) num /= 2;
        }
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                count++;
                while (num % i == 0) num /= i;
            }
        }
        if (num > 1) count++;
        return count;
    }

    //for left
    vector<int>calculateleft(vector<int>&nums){
        int n=nums.size();
        vector<int>vec(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
               
            }
             vec[i]=st.empty()?i:(i-st.top()-1);
                st.push(i);
        }
        return vec;
    }
    //right
    vector<int>calculateright(vector<int>&nums){
        int n=nums.size();
        vector<int>ans(n,0);
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && nums[s.top()]<=nums[i]){
                s.pop();
               
            }
             ans[i]=s.empty()?(n-i-1):(s.top()-i-1);
                s.push(i);
        }
        return ans;
    }
    //modpower
    long long modpow(long long  base,long long exp,long long mod){
        long long result=1;
        while(exp>0){
            if(exp%2==1) result=(result*base)%mod;
            base=(base*base)%mod;
            exp/=2;
        }
        return result;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>primescore(n,0);
        for(int i=0;i<n;i++){
        
           primescore[i]=count(nums[i]);
        }
        vector<int>prefix=calculateleft(primescore);
        vector<int>suffix=calculateright(primescore);
        const int MOD=1e9+7;
        long long ans=1;
        priority_queue<pair<int ,long long>>pq;
        for(int i=0;i<n;i++){
            int left=prefix[i];
            int right=suffix[i];
            long long freq=(left+right+1)+ ((long long)left*right);
            pq.push({nums[i],freq});
        }
        
        while(!pq.empty() && k>0){
            int m=pq.top().first;
            long long freq=pq.top().second;
            pq.pop();
            if(freq>=k){
                ans=(ans*modpow(m,k,MOD))%MOD;
                break;
            }else{
                ans=(ans*modpow(m,freq,MOD))%MOD;
                k-=freq;
            }
        }
        return ans%MOD;
        
    }
};