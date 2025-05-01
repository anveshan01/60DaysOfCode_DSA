// 2071 LeetCode 
/* each worker one task , one pill to one worker to increase stength , go greedy pick the hardest task along with strongest worker
if not strong enough reduce the task by given strength of pill and then check if worker can do it or not
if can do continue to check for the rest of the tasks until the count of pills used is less than or equal to the given pills */
class Solution {
    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            cin.tie(nullptr);
            cout.tie(nullptr);
            int n =tasks.size(), m = workers.size();
            sort(tasks.begin(),tasks.end());
            sort(workers.begin(),workers.end());
            int l = 0, r = min(m,n);
            int ans = 0;
    
            while(l <= r){
                int mid = l + (r - l) / 2;
                int cnt = 0;
                bool flag = true;
    
                multiset<int> st(workers.begin(),workers.end()); // multiset to store workers already sorted and use lower bound
    
                for(int i = mid - 1; i >= 0 ; i--){
                    //strongest worker hardest task
                    auto it = prev(st.end());
                    if(tasks[i] <= *it){
                        //success
                        st.erase(it);
                    } else{
                        // worker with pill
                        auto it = st.lower_bound(tasks[i] - strength); // find the worker with strength >= task - strength 
                        if(it != st.end()){
                            //success
                            cnt++;
                            st.erase(it);
                        } else {
                            // not possible 
                            flag = false;
                            break;
                        }
                    }
                    //no of pills required is more than mid th task requires
                    if (cnt > pills) {
                        flag = false;
                        break;
                    }
                }
                if(flag){ // if cnt is <= pills update ans
                    ans = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            return ans;
        }
    };
// T.C: O(nlogn)
// S.C: O(n)