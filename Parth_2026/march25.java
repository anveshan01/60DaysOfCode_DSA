class Solution {
    private boolean checkCuts(int[][] rectangles, int dim){
        int gaps = 0 ;
        Arrays.sort(rectangles,(a,b)->Integer.compare(a[dim],b[dim])) ;
        int maxEnd = rectangles[0][dim+2] ;//impt logic
        for(int i =1 ;i<rectangles.length ;i++){
            int[] rectangle = rectangles[i] ;
            if(maxEnd<=rectangle[dim]){
                gaps++ ;
            }
            maxEnd = Math.max(maxEnd,rectangle[dim+2]) ;
        }
        return gaps>=2;

    }
    public boolean checkValidCuts(int n, int[][] rectangles) {
        if(rectangles.length<3)
            return false ;
            //0 for horizontal,1 1 for vertical
        return checkCuts(rectangles,0) || checkCuts(rectangles,1) ;
    }
}