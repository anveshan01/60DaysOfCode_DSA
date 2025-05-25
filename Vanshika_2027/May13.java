//https://leetcode.com/problems/finding-3-digit-even-numbers
class Solution {
    public int[] findEvenNumbers(int[] digits) {
        int[] freq= new int[10];
        for(int d:digits) {
            freq[d]++;
        }
        List<Integer> res = new ArrayList<>();

        for(int i = 100;i<=999; i+=2) {
            int[] count = new int[10];
            int temp=i;

            count[temp%10]++;
            temp /= 10;
            count[temp%10]++;
            temp/=10;
            count[temp%10]++;

            boolean canForm = true;
            for(int j=0;j<10;j++) {
                if(count[j]>freq[j]) {
                    canForm=false;
                    break;
                }
            }

            if(canForm){
                res.add(i);
            }
        }

        int[] resArr = new int[res.size()];
        for(int i =0; i<res.size();i++) {
            resArr[i]=res.get(i);
        }

        return resArr;
    }
}