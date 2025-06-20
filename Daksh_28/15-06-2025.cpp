// LeetCode 1432
class Solution {
public:
    int maxDiff(int num) {
        string str1 = to_string(num);
        string str2 = str1;
        int n = str1.size();
        int i;
        for(i = 0; i < n; i++){
            if(str1[i] != '9') break;
        }
        char ele1 = str1[i];
        for(int j = 0; j < n; j++){
            if(str1[j] == ele1) str1[j] = '9';
        }
        char ele2 = str2[0];
        char replace = '1';
        if(ele2 == '1'){
            for(int k = 1; k < n; k++){
                if(str2[k] != '0' && str2[k] != '1'){
                    ele2 = str2[k];
                    replace = '0';
                    break;
                }
            }
        }
        for(int l = 0; l < n; l++){
            if(str2[l] == ele2) str2[l] = replace;
        }
        return stoi(str1) - stoi(str2);
    }
};
// T.C: O(n)
// S.C: O(n)
