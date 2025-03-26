//26-03-2025
//Longest common prefix

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.empty()) {
                return "";  // If the vector is empty, return an empty string
            }
    
            string ans = "";
            int n = strs.size();  // Use strs.size() instead of strs.length()
    
            for (int i = 0; i < strs[0].length(); i++) {
                char ch = strs[0][i];
                bool match = true;
    
                for (int j = 1; j < n; j++) {
                    // Check if the current character is beyond the string length or doesn't match
                    if (i >= strs[j].length() || ch != strs[j][i]) {
                        match = false;
                        break;
                    }
                }
    
                if (!match) {
                    break;
                } else {
                    ans.push_back(ch);
                }
            }
    
            return ans;  // Move return statement here, outside the loop
        }
    };
    