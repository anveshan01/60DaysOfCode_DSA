class Solution {
    public:
        int minimumSwap(int val,vector<int>& tops, vector<int>& bottoms){
            int n=tops.size();
            int topSwap=0;
            int bottomSwap=0;
            for(int i=0;i<n;i++){
                 if(tops[i]!=val && bottoms[i]!=val){
                    return -1;
                 }else if(tops[i]==val && bottoms[i]!=val){
                      topSwap++;
                 }else if(bottoms[i]==val && tops[i]!=val){
                       bottomSwap++;
                 }
            }
            return min(topSwap,bottomSwap);
        }
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int ans=INT_MAX;
            for(int val=1;val<=6;val++){
                int swap=minimumSwap(val,tops,bottoms);
                if(swap!=-1){
                    ans=min(ans,swap);
                }
            }
            return ans==INT_MAX?-1:ans;
            
        }
    };