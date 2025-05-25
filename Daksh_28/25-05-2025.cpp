// LeetCode 2131 
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mpp;
        for(auto &word : words) mpp[word]++;

        int len = 0;
        bool hasCenter = false;
        for(auto &[word, count] : mpp) {
            string reverse_word = string() + word[1] + word[0];
            if(reverse_word == word) {
                int pairs = count / 2;
                len += 4 * pairs;
                if(count % 2 == 1 && !hasCenter) {
                    len += 2;
                    hasCenter = true;
                }
            }
            else if(mpp.find(reverse_word) != mpp.end()) {
                len += 4 * min(count, mpp[reverse_word]);
                mpp[word] = 0;
                mpp[reverse_word] = 0;
            }
        }

        return len;
    }
};
// T.C O(n)
// S.C O(n)
