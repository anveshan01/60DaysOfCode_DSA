class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int count = 0  ;
        for(int i=low ;i<=high ;i++){
            String str = String.valueOf(i) ;
            if(str.length()%2==0){
                int left = 0 ;
                int right = 0 ;
                int j=0 ;
                int k = str.length()-1 ;
                while(j<=k){
                    left+=str.charAt(j) - '0' ;
                    right+= str.charAt(k) - '0';
                    j++ ;
                    k-- ;
                }
                if(left==right) count++ ;
            }
        }
        return count ;
    }
}