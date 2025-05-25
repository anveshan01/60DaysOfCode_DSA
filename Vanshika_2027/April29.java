// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string
class Solution {
    public int strStr(String haystack, String needle) {
        int lenH = haystack.length();
        int lenN = needle.length();

        if (lenH < lenN) return -1;
        for (int i = 0; i <= lenH - lenN; i++){
            String substr = haystack.substring(i, i+lenN);
            if (substr.equals(needle))
                return i;
        }
        return -1;

    }
}