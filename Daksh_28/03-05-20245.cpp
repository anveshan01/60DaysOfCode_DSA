// LeetCode 1007 
class Solution {
    public:
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            cin.tie(nullptr);
            cout.tie(nullptr);
            int n=tops.size();
            unordered_map<int,int>mp;
            for(int i=0;i<n;i++){
                if(tops[i]==bottoms[i]){
                    mp[tops[i]]++;
                }
                else{
                    mp[tops[i]]++;
                    mp[bottoms[i]]++;
                }
            }
            vector<int>v;
            for(auto &it:mp){
                if(it.second==n){
                    v.push_back(it.first);
                }
            }
            int ans=n+1;
            for(auto x:v){
                int c=0;
                for(int i=0;i<n;i++){
                    if(tops[i]!=x){
                        c++;
                    }
                }
                ans=min(ans,c);
            }
            for(auto x:v){
                int c=0;
                for(int i=0;i<n;i++){
                    if(bottoms[i]!=x){
                        c++;
                    }
                }
                ans=min(ans,c);
            }
            return ans==n+1?-1:ans;
        }
    };
// Time Complexity: O(n)
// Space Complexity: O(n)