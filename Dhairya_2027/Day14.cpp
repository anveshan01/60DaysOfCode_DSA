//25-03-2025
//POTD LEETCODE25

class Solution {
    public:
        bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
            return isValidCut(rectangles, 0, 0, 2) || isValidCut(rectangles, 1, 1, 3);
        }
    
    private:
        bool isValidCut(vector<vector<int>>& rectangles, int sortIndex, int start, int end) {
            sort(rectangles.begin(), rectangles.end(), [&](const vector<int>& a, const vector<int>& b) {
                return a[sortIndex] < b[sortIndex];
            });
    
            int currentStart = rectangles[0][start];
            int currentEnd = rectangles[0][end];
            int intervals = 0;
    
            for (const auto& rect : rectangles) {
                if (rect[start] < currentEnd) {
                    currentEnd = max(rect[end], currentEnd);
                } else {
                    intervals++;
                    currentStart = rect[start];
                    currentEnd = rect[end];
                }
            }
            intervals++;
    
            return intervals > 2;
        }
    };