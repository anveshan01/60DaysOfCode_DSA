// 12-03-2025 
// kth smallest heap

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> pq;
       
        // Push first k elements into the max heap
        for (int i = 0; i < k; i++) {
            pq.push(arr[i]);
        }
        
        // Process the remaining elements
        for (int i = k; i < arr.size(); i++) {
            if (arr[i] < pq.top()) {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        return pq.top();
    }
};

int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    Solution sol;
    cout << "The " << k << "th smallest element is: " << sol.kthSmallest(arr, k) << endl;
    return 0;
}