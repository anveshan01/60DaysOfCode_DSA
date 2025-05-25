// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
class Solution {
    public int maxProfit(int[] prices) {
        if (prices==null || prices.length==0) return 0;
        int n=prices.length;
        int hold=-prices[0];  //hold on day 0
        int sold=0;           //just sold
        int rest=0;           //resting

        for(int i=1;i<n;i++){
            int prevHold=hold;
            int prevSold=sold;
            int prevRest=rest;

            hold = Math.max(prevHold, prevRest-prices[i]);  //buy or hold
            sold = prevHold+prices[i];                      //sell
            rest = Math.max(prevRest,prevSold);             //cooldown or rest
        }
        return Math.max(sold,rest);
    }
}

// https://leetcode.com/problems/find-words-containing-character/
class Solution {
    public List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> res = new ArrayList<>();

        for(int i = 0; i<words.length;i++){
            if(words[i].indexOf(x) != -1){
                res.add(i);
            }
        }
        return res;
    }
}