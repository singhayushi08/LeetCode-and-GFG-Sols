class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Simple graph BFS, TC: O(N + wordLength * 26), SC: O(N)
        set<string> s;
        for(auto it: wordList) {
            s.insert(it);
        }
        s.erase(beginWord);
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        while(!q.empty()) {
            string str = q.front().first;
            int seq = q.front().second;
            q.pop();
            if(str == endWord) return seq;
            
            for(int i=0; i<str.size(); i++) {
                char original = str[i];
                for(char ch='a'; ch<='z'; ch++) { // try every possible char from a-z for each letter in the word
                   str[i] = ch;
                   if(s.find(str) != s.end()) { // word found in set
                       q.push({str, seq+1});
                       s.erase(str);
                   } 
                }
                str[i] = original;
            }
        }
        
        return 0;
    }
};