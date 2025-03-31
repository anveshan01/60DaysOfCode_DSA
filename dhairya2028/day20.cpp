//leetcode 344. Reverse String
class Solution {
public:
    void reverseString(vector<char>& s) {
        int st=0,end=s.size()-1;
        while(st<end){
            swap(s[st],s[end]);
            st++;end--;
        }
    }
};

//1910. Remove All Occurrences of a Substring
class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        while(s.length()>0 && s.length()>s.find(part)){
            s.erase(s.find(part),part.length());
        }
        return s;
    }
};
