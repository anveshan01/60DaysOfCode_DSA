class Solution {
    public:
        string countAndSay(int n) {
            string ans="1";
            for(int i=1;i<n;i++){
                string temp="";
                int count=1;
                for(int j=1;j<ans.size();j++){
                    if(ans[j]==ans[j-1]){
                        count++;
                    }else{
                        temp+=to_string(count)+ans[j-1];
                        count=1;
                    }
                }
                temp+=to_string(count)+ans.back();
                ans=temp;
            }
           return ans; 
        }
    };