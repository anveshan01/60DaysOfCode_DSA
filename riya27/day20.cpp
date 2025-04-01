class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            queue<pair<string,int>>q;
            q.push({beginWord,1});
            unordered_set<string>st(wordList.begin(),wordList.end());
            //erase the word if we find it in wordlist
            st.erase(beginWord);
            while(!q.empty()){
                string word=q.front().first;
                int steps=q.front().second;
                q.pop();
                if(word==endWord) return steps;
                //traverse each char of word to find poss combinations
                for(int i=0;i<word.length();i++){
                    char original=word[i];
                    for(int j='a';j<='z';j++){
                        word[i]=j;
                         if(st.find(word)!=st.end()){
                          st.erase(word);
                          q.push({word,steps+1});
                    }
                    }
                    word[i]=original; //keep the original word
                    }
                }
            return 0;
        }
    };