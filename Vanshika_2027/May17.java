//https://leetcode.com/problems/longest-substring-without-repeating-characters
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int i = 0, max = 0, start = 0;
        String ans = "";
        String str = "";

        while (i < s.length()) {
            if (str.contains(String.valueOf(s.charAt(i)))) {
                if (str.length() > max) {
                    ans = str;
                    max = ans.length();
                }
                int index = str.indexOf(s.charAt(i));
                start = start + index + 1;
                str = s.substring(start, i + 1);
            } else {
                str = s.substring(start, i + 1);
            }
            i++;
        }

        if (str.length() > max) {
            ans = str;
            max = ans.length();
        }

        return max;
    }
}