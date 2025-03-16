// 16-03-2025
// POTD 16 LEETCODE

class Solution {
    public:
        bool check(vector<int> rank , long long i , int n){
            long long cars = 0;
            for(int r : rank){
                long long sq = i/r;
                cars += sqrt(sq);
            }
            return cars >= n;
        }
        long long repairCars(vector<int>& ranks, int cars) {
            long long l = 1 , r = 1e14;
            while(l<r){
                long long mid = l + (r-l)/2;
                if(check(ranks,mid,cars)) r = mid;
                else{
                    l = mid+1;
                }
            }
            return l;
        }
    };

// integer to roman number

    class Solution {
        public:
            string intToRoman(int num) {
                string roman;
                vector<string>  notations = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
                vector<int> value = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        
                int i = 0;
                while(num > 0){
                    while(num >= value[i]){
                        roman += notations[i];
                        num -= value[i];
                    }
                    i++;
                }
                return roman;
            }
        };