// LeetCode 3442 
class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {0};
        int maxOdd = 0;
        int minEven = INT_MAX;

        for(char c : s){
            freq[c - 'a']++;
        }

        for(int i=0; i<26; i++){
            int count = freq[i];
            if(count == 0) continue;
            if(count % 2 == 1){
                maxOdd = max(maxOdd, count);
            } else {
                minEven = min(minEven, count);
            }
        }

        return maxOdd - minEven;
    }
};
// T.C: O(n) 
// S.C: O(1)
