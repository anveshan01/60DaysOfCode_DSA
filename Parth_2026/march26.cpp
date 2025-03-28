class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            vector<int> arr ;
            int result = 0 ;
            for(int row = 0; row<grid.size() ;row++){
                for(int col = 0; col<grid[0].size() ;col++){
                    arr.push_back(grid[row][col]) ;
                }
            }
            int length = arr.size() ;
            nth_element(begin(arr),begin(arr)+ length/2, end(arr)) ;
    
            int finalCommon = arr[length/2] ;
            for(int num : arr){
                if(num %x != finalCommon%x) return -1 ;
                result+=abs(finalCommon-num)/x ;
            }
            return result ;
        }
    };