// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
    public String longestPalindrome(String s) {
        if(s.length()<=1) return s;

        String result="";
        //odd length
        for (int i=1; i<s.length();i++){
            int low=i;
            int high=i;

            while(s.charAt(low)==s.charAt(high)){
                low--;
                high++;

                if (low==-1 || high==s.length()) break;
            }

            String pal = s.substring(low+1,high);

            if(pal.length()>result.length()){
                result= pal;
            }

            //even length
            low = i-1;
            high=i;

            while(s.charAt(low)==s.charAt(high)){
                low--;
                high++;

                if (low==-1 || high==s.length()) break;
            }

            pal = s.substring(low+1,high);

            if(pal.length()>result.length()){
                result= pal;
            }
        }
        return result;
    }
}