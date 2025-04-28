class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int ans = 0 ;
            unordered_map<int,int> mp ;
            for(auto it : answers){
                mp[it]++ ;
            }
            for(auto it : mp){
                int size = it.first +1 ;
                int num = it.second/size ;
                if(it.second%size){
                    num++ ;
                   
                }
                 ans+=(num*size) ;
            }
            return ans ;
        }
    };