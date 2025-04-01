//https://leetcode.com/problems/max-consecutive-ones/
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int count = 0;
        int res = 0;
        for(int num: nums){
            if(num!=1){
                count = 0;
            }else{
                count++;
            }
            res = Math.max(res,count);
        }
        return res;
    }
}

//https://leetcode.com/problems/first-unique-character-in-a-string/
class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> freqMap = new HashMap<>();

        for (char c : s.toCharArray()){
            if(freqMap.containsKey(c)){
                freqMap.put(c, freqMap.get(c)+1);
            } else{
                freqMap.put(c,1);
            }
        }

        for (int i=0; i<s.length(); i++){
            if (freqMap.get(s.charAt(i))==1){
                return i;
            }
        }
        return -1;
    }
}