class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix[0].size();
        int m=matrix.size();
        int strow=0,endrow=m-1;
        while(strow<=endrow){
            int midrow=strow+(endrow-strow)/2;
            if(target>=matrix[midrow][0] && target<=matrix[midrow][n-1]){
                int st=0;int end=n-1;
                while(st<=end){
                    int mid=st+(end-st)/2;
                    if(matrix[midrow][mid]==target) return true;
                    else if (matrix[midrow][mid]<target) st=mid+1;
                    else end=mid-1;
                }
                return false;
            }
            else if(matrix[midrow][n-1]<target) strow=midrow+1;
            else endrow=midrow-1;
        }
        return false;
         
    }
};
