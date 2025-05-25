// https://leetcode.com/problems/add-binary/
class Solution {
    public String addBinary(String a, String b) {
        int len1 = a.length()-1;
        int len2 = b.length()-1;
        int carry = 0;
        StringBuilder result = new StringBuilder();

        while(len1>=0 || len2>=0){
            int sum = carry;
            if(len1>=0){
                sum+=a.charAt(len1--)-'0';
            }
            if(len2>=0){
                sum+=b.charAt(len2--)-'0';
            }
            result.append(sum%2);
            carry = sum/2;
        }

        if(carry!=0){
            result.append(carry);
        }
        return result.reverse().toString();
    }
}