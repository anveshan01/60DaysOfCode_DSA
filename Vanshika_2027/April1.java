//https://leetcode.com/problems/rotting-oranges/
class Solution {
    public int orangesRotting(int[][] grid) {
        if(grid==null || grid.length==0) return -1;
        int r = grid.length, c = grid[0].length;
        int fresh=0;
        Queue<int[]> q = new LinkedList<>();

        for(int i =0; i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 2){
                    q.add(new int[]{i,j});
                }else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        if(fresh==0) return 0;
        int[][] dxn = {{-1,0},{1,0},{0,-1},{0,1}};
        int t =0;

        while(!q.isEmpty()){
            int n = q.size();
            t++;
            for(int i =0; i<n ;i++){
                int[] rot = q.remove();
                int x = rot[0], y=rot[1];

                for(int[] d : dxn){
                    int nx = x+d[0], ny = y+d[1];

                    if(nx>=0 && ny>=0 && nx<r && ny<c && grid[nx][ny]==1){
                        grid[nx][ny] =2;
                        fresh--;
                        q.add(new int[]{nx,ny});
                    }
                }
            }
        }
        return (fresh==0) ? t-1 : -1;
    }
}