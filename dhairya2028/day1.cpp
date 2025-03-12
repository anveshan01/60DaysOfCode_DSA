class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        

        int n = matrix.size(); 
        int col = matrix[0].size(); 
        int row = 0, upper = col - 1;  
        int down = n - 1, left = 0;  
        
        vector<int> arr;

        while (left <= upper && row <= down) {
            
            for (int i = left; i <= upper; i++) 
                arr.push_back(matrix[row][i]);
            row++; 

         
            for (int i = row; i <= down; i++) 
                arr.push_back(matrix[i][upper]);
            upper--; 

           
            if (row <= down) {
                for (int i = upper; i >= left; i--) 
                    arr.push_back(matrix[down][i]);
                down--; 
            }

           
            if (left <= upper) {
                for (int i = down; i >= row; i--) 
                    arr.push_back(matrix[i][left]);
                left++; 
            }
        }

        return arr;
    }
};
