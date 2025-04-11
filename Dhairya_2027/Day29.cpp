//9-4-2025

class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            unordered_set<int> uniqueNum;
    
            for (int num : nums) {
                if (num < k) return -1;
                if (num > k) uniqueNum.insert(num);
            }
    
            return uniqueNum.size();
        }
    };
    