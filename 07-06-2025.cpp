// LeetCode 386
class Solution {
public:
    void solve(int curr, int n, vector<int>& result){
        if(curr > n){
            return;
        }
        result.push_back(curr);
        for(int append = 0; append <= 9; append++){
            int newNumber = curr*10 + append;

            if(newNumber > n){
                return;
            }
            solve(newNumber,n,result);
        }

    }
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1 ; i <= 9; i++){
            solve(i,n,result);
        }
        return result;
    }
};
// T.C: O(n)
// S.C: O(n)