// 3335 LeetCode 
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int MOD = 1e9+7;
        vector<int> mp(26, 0);
        for(char ch: s){
            mp[ch-'a']++;
        }
        for(int cnt=1; cnt<=t; cnt++){
            vector<int> temp(26, 0);
            for(int i=0; i<26; i++){
                if(i == 25){
                    temp[0] = (temp[0] + mp[i]) % MOD;
                    temp[1] = (temp[1] + mp[i]) % MOD;
                }else {
                    temp[i+1] = (temp[i+1] + mp[i]) % MOD;
                }
            }
            mp = temp;
        }
        int len = 0;
        for(int num: mp){
            len = (len + num) % MOD;
        }
        return len;
    }
};
// T.C : O(t)
// S.C : O(1)