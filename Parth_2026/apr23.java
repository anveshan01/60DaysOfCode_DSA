class Solution {
    public int countLargestGroup(int n) {
        Map<Integer,Integer> mp = new HashMap<Integer,Integer>() ;
        int max = 0 ;
        for(int i=1 ;i<=n ;i++){
            int key = 0 , temp = i ;
            while(temp>0){
                key+= temp%10 ;
                temp/=10 ;
            }
            mp.put(key,mp.getOrDefault(key,0)+1) ;
            max = Math.max(max,mp.get(key)) ;
        }
        int count= 0 ;
        for(Map.Entry<Integer,Integer> pair : mp.entrySet()){
            if(pair.getValue() == max){
                count++ ;
            }
        }
        return count ;
    }
}