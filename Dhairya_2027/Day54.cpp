class Solution 
{
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        // Step 1: Frequency array for normalized keys
        int count[100] = {0};  
        
        // Step 2: Initialize result
        int result = 0;        

        // Step 3: Traverse each domino
        for (auto& d : dominoes) 
        {  
            int a = d[0], b = d[1];
            
            // Step 4: Normalize
            int key = min(a, b) * 10 + max(a, b);  

            // Step 5: Add existing pairs to result
            result += count[key]; 
            
            // Step 6: Increment count
            count[key]++;          
        }

        // Step 7: Return final count
        return result;  
    }
};