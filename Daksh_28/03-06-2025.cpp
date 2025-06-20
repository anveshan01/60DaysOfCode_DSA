// LeetCode 3403 
class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1){
            return word;
        }
        int n = word.size();
        string ans;
        for(int i = 0; i < n; i++){
            ans = max(ans, word.substr(i, word.length() - numFriends + 1));
        }
        return ans;
    }
};
// T.C: O(n^2)
// S.C: O(n)