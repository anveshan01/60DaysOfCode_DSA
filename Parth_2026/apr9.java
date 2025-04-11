class Solution {
    public:
    
        long long solve(string& str, string& inputSuffix, int limit){
            if(str.length()<inputSuffix.length()){
                return 0 ;
            }
            long long count = 0 ;
            string trailString = str.substr(str.length()-inputSuffix.length()) ;
    
            int remL = str.length() - inputSuffix.length() ;
            for(int i=0 ;i<remL ;i++){
                int digit = str[i] - '0' ;
    
                if(limit>=digit){
                    count += digit*pow(limit+1,remL-i-1) ;
                }
                else{
                    count += pow(limit+1,remL-i) ;
                    return count ;
                }
            }
    
            if(trailString >= inputSuffix){
                count+=1 ;
            }
            return count ;
        }
        long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
            string startStr = to_string(start-1) ;
            string f = to_string(finish) ;
            return solve(f,s,limit) - solve(startStr,s,limit) ;
        }
    };