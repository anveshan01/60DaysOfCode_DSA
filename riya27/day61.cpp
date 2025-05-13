ublic:
    int lengthAfterTransformations(string s, int t) {
        int MOD=1000000007;
        vector<int>count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']++;
        }
        while(t>0){
            vector<int>temp(26,0);
            for(int i=0;i<26;i++){ 
                if(i==25){
                    temp[0]=(temp[0]+count[25])%MOD;
                      temp[1]=(temp[1]+count[25])%MOD;
                }
                else temp[i+1]=(temp[i+1]+count[i])%MOD;
            }
            count=temp;
            t--;
        }
        int ans=0;
        for(auto it:count){
            ans=(ans+it)%MOD;
        }
       return ans; 
    }
};