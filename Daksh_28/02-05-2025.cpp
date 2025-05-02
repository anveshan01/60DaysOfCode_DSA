// 838 Push Dominoes
// OK 101
class Solution {
    public:
        string pushDominoes(string dominoes) {
            int n = dominoes.length();
            
            vector<int> rightcl(n);
            vector<int> leftcr(n);
            
            for(int i = n-1; i>=0; i--) {
                if(dominoes[i] == 'L')
                    rightcl[i] = i; //L starts from me
                else if(dominoes[i] == '.')
                    rightcl[i] = i < n-1 ? rightcl[i+1] : -1;
                else
                    rightcl[i] = -1;
            }
            
            //Moving leftcr to rightcl to find left closest R
            for(int i = 0; i<n; i++) {
                if(dominoes[i] == 'R')
                    leftcr[i] = i; //R starts from me
                else if(dominoes[i] == '.')
                    leftcr[i] = i > 0 ? leftcr[i-1] : -1;
                else
                    leftcr[i] = -1;
            }
            
            string result(n, ' ');
            
            for(int i = 0; i<n; i++) {
                int distRightL = abs(i-rightcl[i]); //distance from 'R' towards my left closest R
                int distLeftR  = abs(i-leftcr[i]);  //distance from 'L' towards my right closest L 
                
                if(rightcl[i] == leftcr[i])
                    result[i] = '.';
                else if(rightcl[i] == -1)  //No force from rightcl towards leftcr, so move R
                    result[i] = 'R';
                else if(leftcr[i] == -1)   //No force from leftcr towards rightcl, so move L
                    result[i] = 'L';
                else if(distLeftR == distRightL) //Equal force from left closest R and right closest L
                    result[i] = '.';
                else
                    result[i] = distRightL < distLeftR ? 'L': 'R'; //which ever force is greater
            }
            
            return result;
        }
    };
// Time Complexity: O(n)
// Space Complexity: O(n)
