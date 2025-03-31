//29-03-2025


class Solution {
    private:
        // to calculate left
        vector<int> countConsecutiveSmaller(vector<int>& nums) {
            int n = nums.size();
            vector<int> ans(n, 0);
            stack<int> st;
            for (int i = 0; i < n; i++) {
                while (!st.empty() && nums[st.top()] < nums[i]) 
                    st.pop();
                ans[i] = st.empty() ? i : (i - st.top() - 1);
                st.push(i);
            }
            return ans;
        }
    
       // to calculate right
    
        vector<int> countConsecutiveSmallerRight(vector<int>& nums) {
            int n = nums.size();
            vector<int> res(n, 0);
            stack<int> st;
    
            for (int i = n - 1; i >= 0; i--) {
                while (!st.empty() && nums[st.top()] <= nums[i]) 
                    st.pop();
                res[i] = st.empty() ? (n - i - 1) : (st.top() - i - 1);
                st.push(i);
            }
            return res;
        }
    
        // to calculate scores (numberOfDistinctPrime)
    
        int f(int num) {
            if (num <= 1) return 0;
            int count = 0;
            if (num % 2 == 0) {
                count++;
                while (num % 2 == 0) num /= 2;
            }
            for (int i = 3; i * i <= num; i += 2) {
                if (num % i == 0) {
                    count++;
                    while (num % i == 0) num /= i;
                }
            }
            if (num > 1) count++;
            return count;
        }
        // for modPower
        long long modPow(long long base, long long exp, long long mod) {
            long long result = 1;
            while (exp > 0) {
                if (exp % 2 == 1) result = (result * base) % mod;
                base = (base * base) % mod;
                exp /= 2;
            }
            return result;
        }
    public:
        int maximumScore(vector<int>& nums, int k) {
            int n = nums.size();
            vector<int> numberOfDistinctPrime(n, 0);
            for (int i = 0; i < n; i++) {
                numberOfDistinctPrime[i] = f(nums[i]);
            }
    
            vector<int> pre = countConsecutiveSmaller(numberOfDistinctPrime);
            vector<int> suff = countConsecutiveSmallerRight(numberOfDistinctPrime);
    
            const int MOD = 1e9 + 7;
            long long ans = 1;
            priority_queue<pair<int, long long>> pq;
    
            for (int i = 0; i < n; i++) {
                int l = pre[i];
                int r = suff[i];
                long long freq = (l + r + 1) + ( (long long)l * r); 
                pq.push({nums[i], freq});
            }
    
            while (!pq.empty() && k > 0) {
                int t = pq.top().first;
                long long freq = pq.top().second;
                pq.pop();
    
                if (freq >= k) {
                    ans = (ans * modPow(t, k, MOD)) % MOD;
                    break;
                } else {
                    ans = (ans * modPow(t, freq, MOD)) % MOD;
                    k -= freq;
                }
            }
    
            return ans%MOD;
        }
    };
        
            
        
    