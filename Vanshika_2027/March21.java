//https://www.naukri.com/code360/problems/aggressive-cows_1082559
import java.util.*;
public class Solution {
    public static int aggressiveCows(int []stalls, int k) {
        int n = stalls.length;
        Arrays.sort(stalls);
        int s =1, e = stalls[n-1]-stalls[0];
        while(s<=e){
            int m = s+(e-s)/2;
            if(canWePlace(stalls, m, k, n)){
                s=m+1;
            }else{
                e=m-1;
            }
        }
        return e;
    }
    public static boolean canWePlace(int[] stalls, int dist, int cows, int n){
        int count =1;
        int last = stalls[0];
        for(int i =1; i<n;i++){
            if(stalls[i]-last>=dist){
                count++;
                last = stalls[i];
            }
            if(count>=cows) return true;
        }
        return false;
    }
}

//https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
class Solution {
    public int maximumCandies(int[] candies, long k) {
        long s =1, e=0,sum=0;
        for(int candy : candies){
            e = Math.max(e,candy);
            sum+=candy;
        }
        if(sum<k) return 0;

        while(s<=e){
            long m = s+(e-s)/2;
            if(canDistribute(candies, k, m)){
                s=m+1;
            }else{
                e=m-1;
            }
        }
        return (int)e;
    }
    public static boolean canDistribute(int[] candies, long k, long m){
        long count =0;
        for(int candy :candies){
            count+=candy/m;
            if(count>=k) return true;
        }
        return false;
    }
}

//https://leetcode.com/problems/split-array-largest-sum/description/
class Solution {
    public int splitArray(int[] nums, int k) {
        int n = nums.length;
        int s =0, e =0;
        for(int num : nums){
            s= Math.max(num,s);
            e += num;
        }
        while(s<e){
            int m = s+(e-s)/2;
            int sum =0, pcs =1;
            for(int num:nums){
                if(sum+num > m){
                    pcs++;
                    sum = num;
                }else{
                    sum+=num;
                }
            }
            if(k<pcs){
                s=m+1;
            }else{
                e=m;
            }
        }
        return s;
    }
}

//https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int s = matrix[0][0], e = matrix[n-1][n-1];

        while(s<e){
            int m = s+(e-s)/2;
            int count = countLessEqual(matrix, m, n);
            if(count<k){
                s=m+1;
            }else{
                e=m;
            }
        }
        return s;
    }
    public int countLessEqual(int[][] matrix,int mid, int n){
        int count =0, i = n-1, j=0;

        while(i>=0 && j<n){
            if(matrix[i][j]<=mid){
                count += i+1;
                j++;
            }else{
                i--;
            }
        }
        return count;
    }
}