class Solution {
    vector<int>Nse(vector<int>&row){
        int n=row.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && row[st.top()]>=row[i]){
                st.pop();
            }
            ans[i]=st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>Pse(vector<int>&row){
        int n=row.size();
        stack<int>st;
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && row[st.top()]>row[i]){
                st.pop();
            }
            ans[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    int largestrectangle(vector<int>&rows){
       int n=rows.size(); 
       vector<int>nse=Nse(rows);
       vector<int>pse=Pse(rows);
       int ans=0;
       for(int i=0;i<n;i++){
        int l=rows[i];
        int b=nse[i]-pse[i]-1;
        int pro=l*b;
        ans=max(ans,pro);

       }
       return ans; 
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
       int m=matrix.size();
       int n=matrix[0].size();
       int maxarea=0;
       vector<int>rows(n,0);
       for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((matrix[i][j]-'0')==1){
                    rows[j]+=1;
                }else{
                    rows[j]=0;
                }
            }
           maxarea=max(maxarea,largestrectangle(rows));
       } 
      return maxarea;
    }
};