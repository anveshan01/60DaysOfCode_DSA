class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int idx = 1, res = 0;
        int n = arr.size();
        while (idx < n)
        {
            int ups = 0, downs = 0;
            while (idx < n && arr[idx] > arr[idx - 1])
            {
                ups++;
                idx++;
            }
            while (idx < n && arr[idx] < arr[idx - 1])
            {
                downs++;
                idx++;
            }
            if (ups && downs)
                res = max(res, ups + downs + 1);
            else if (!ups and !downs)
                idx++;
        }
        return res;
    }
};
// T.C: O(n)
// S.C: O(1)