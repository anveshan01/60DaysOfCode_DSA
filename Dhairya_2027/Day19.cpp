//30-03-2025


class Solution {

    public:
    
        vector<int> partitionLabels(string& s) {
    
            const int n=s.size();
    
            array<pair<int, int>, 26> P;// (start, end)
    
            P.fill({n, -1});
    
            for(int i=0; i<n; i++){
    
                int x=s[i]-'a';
    
                P[x].first=min(i, P[x].first);
    
                P[x].second=i;
    
            } 
    
            // Process the intervals
    
            vector<int> pLen;
    
            int start = 0, end = -1;
    
            for (int i = 0; i < n; i++) {
    
                int x = s[i] - 'a';
    
                end = max(end, P[x].second);
    
                if (i == end) {
    
                    pLen.push_back(end - start + 1);
    
                    start = i + 1;
    
                }
    
            }
    
            return pLen;
    
        }
    
       
    
    };
        
           
        
    