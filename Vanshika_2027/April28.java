// https://leetcode.com/problems/zigzag-conversion/
class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) return s;

        String[] str = new String[numRows];

        for (int i=0; i<numRows; i++) {
            str[i]="";
        }

        int i = 0;
        while (i<s.length()) {
            for (int index = 0; (index < numRows && i < s.length()); index++) {
                str[index] += s.charAt(i++);
            }
            for (int index = numRows - 2; (index > 0 && i < s.length()); index--) {
                str[index] += s.charAt(i++);
            }
        }

        String result = "";
        for (String temp : str) {
            result += temp;
        }
        return result;
    }
}