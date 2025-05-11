using namespace std;
#include <vector>
using namespace std;

int search(vector<int>& arr, int n, int k) {
    int st = 0, end = n - 1;

    while (st < end) {
        int mid = st + (end - st) / 2;
        if (arr[mid] > arr[end]) {
            st = mid + 1;
        } else {
            end = mid;
        }
    }
    int pivot = st;

    if (k >= arr[pivot] && k <= arr[n - 1]) {
        st = pivot;
        end = n - 1;
    } else {
        st = 0;
        end = pivot - 1;
    }

 
    while (st <= end) {
        int mid = st + (end - st) / 2;
        if (arr[mid] == k) {
            return mid;
        } else if (arr[mid] < k) {
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}
