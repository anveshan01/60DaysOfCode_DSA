// LeetCode 2566
class Solution {
public:
    int minMaxDifference(int num) {
        string str = to_string(num);
        string max = "";
        string min = "";
        int n = str.size();
        char ele = ' ';
        for(int i = 0; i < n; i++){
            if(str[i] != '9'){
                ele = str[i];
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(ele == str[i]) max += '9';
            else max += str[i];
        }
        for(int i=0;i<n;i++){
            if(str[0] == str[i]) min += '0';
            else min += str[i];
        }
        return stoi(max) - stoi(min);
    }
};
// T.C: O(n)
// S.C: O(n) 