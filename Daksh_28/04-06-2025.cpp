// LeetCode 1061
class Solution {
    int  Find_root(int n,vector<int> &mp){   
        if(mp[n]==n)
           return n;     
        return Find_root(mp[n],mp);
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> mp(26);
        for(int i = 0 ; i < 26 ; i++){
            mp[i] = i;
        }
        int cnt = 1;
        for(int i = 0 ; i < s1.length() ; i++){  
             int r1 = Find_root(s1[i]-'a',mp);    
             int r2 = Find_root(s2[i]-'a',mp); 
             if(r1 < r2){
                mp[r2] = r1 ;
             } else {
                mp[r1] = r2;
             }          
        }
        for(auto &ch : baseStr){
             char c = ch;
             while( c != mp[c-'a'] + 'a'){
                 c = mp[c-'a'] + 'a';
             }
             ch = c;
        }
        return baseStr ;
    }
};
// T.C: O(n)
// S.C: O(1)