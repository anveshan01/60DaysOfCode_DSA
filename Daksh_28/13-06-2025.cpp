// LeetCode 2616
class Solution {
public:
    bool valid(vector<int>&  nums, int mid, int p,int n){
        int i = 0;
        int pairs = 0;
        while(i < n-1){
            if(nums[i+1] - nums[i] <= mid){ // pairs with value less than or equal to mid since we have to find
                pairs++;
                i += 2;//skip both elements when pair is made no repeating
            }
            else{
                i++; // skip to next if none
            }
        }
        return pairs >= p;
    }
    int minimizeMax(vector<int>& arr, int p) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int l = 0; // why not arr[0] beacuse min diff bw pairs can be 0 arr[0] isn't necessarily 0
        int r = arr[n-1] - arr[0];
        int res = -1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(valid(arr,mid,p,n)){
                res = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return res;
    }
};
// T.C: O(nlogn) for sorting and O(n) for valid function, so overall O(nlogn)
// S.C: O(1) for space used in valid function
