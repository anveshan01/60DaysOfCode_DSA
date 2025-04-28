// https://leetcode.com/problems/maximal-rectangle/
class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length==0) return 0;

        int maxA=0;
        int cols=matrix[0].length;
        int[] hts=new int[cols];

        for (char[] row: matrix) {
            for (int j=0; j<cols; j++) {
                if (row[j]== '1') {
                    hts[j]++;
                } else {
                    hts[j]=0;
                }
            }
            maxA=Math.max(maxA, largestRect(hts));
        }

        return maxA;
    }

    public int largestRect(int[] hts) {
        Stack<Integer> s = new Stack<>();
        int maxA = 0, n = hts.length;

        for (int i=0; i<=n; i++) {
            int currH = (i==n) ? 0 : hts[i];
            while (!s.isEmpty() && currH<hts[s.peek()]) {
                int h =hts[s.pop()];
                int w =s.isEmpty() ? i : i-s.peek()-1;
                maxA = Math.max(maxA, h*w);
            }
            s.push(i);
        }
        return maxA;
    }
}