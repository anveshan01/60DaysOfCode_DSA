class Solution {
    public:
        int numberOfArrays(vector<int>& differences, int lower, int upper) {
            int n=differences.size();
            int count=0;
            int a=0;
            int b=0;
            for(int i=0;i<n;i++){
                count+=differences[i];
                a=min(a,count);
                b=max(b,count);
                if(b-a>upper-lower){
                    return 0;
                }
            }
            return (upper-lower)-(b-a)+1;
            
        }
    };