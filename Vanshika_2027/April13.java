//https://leetcode.com/problems/rotate-image/
class Solution {
    public void rotate(int[][] matrix) {
        int len = matrix.length;

        for (int i=0; i<len; i++){
            for (int j=i; j<len; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for (int i=0; i<len; i++){
            int left = 0;
            int right = len-1;

            while(left<right){
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
                left++;
                right--;
            }
        }
    }
}