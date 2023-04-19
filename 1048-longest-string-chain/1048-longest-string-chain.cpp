class Solution {
    bool checkPossible(string &s1, string &s2) { // check if diff of (s2-s1) is 1 char
        if(s1.size() != s2.size()+1) return false;
        int i = 0, j = 0;
        
        while(i < s1.size()) {
            if(j < s2.size() && s1[i] == s2[j]) { // if both match
                i++;
                j++;
            }
            else { // do not match, move i only coz s1 is longer
                i++;
            }
        }
        
        if(i == s1.size() && j == s2.size()) return true; // if both reach end then diff was 1 char only, so true
        return false;
    }
    
    static bool comp(string &s1, string &s2) {
        return s1.size() < s2.size(); // sort words[] acc. to increasing length
    }
    
public:
    int longestStrChain(vector<string>& words) { // Ques is just like Longest Increasing Subsequence
        int n = words.size();
        if(n == 1) return 1;
        
        sort(words.begin(), words.end(), comp); // sort words by length(ascending) 
        
        vector<int> dp(n, 1);
        
        int maxi = 1;
        for(int i=0; i<n; i++) {
            for(int prev=0; prev<i; prev++) {
                if(checkPossible(words[i], words[prev]) == true && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(dp[i], maxi);
        }
        
        return maxi;
    }
};