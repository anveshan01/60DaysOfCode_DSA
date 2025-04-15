class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int row=0; int col=m-1;
        while(row<n && col>=0){
            if(target==matrix[row][col]) return true;
            else if(target<matrix[row][col]) col--;
            else row++;
        }
        return false;
    }
};
