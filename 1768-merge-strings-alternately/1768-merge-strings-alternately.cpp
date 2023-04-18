class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int m = word1.size();
        int n = word2.size();
        
        int i=0, j=0;
        while(i < m && j < n) {
            ans.push_back(word1[i]);
            i++;
            ans.push_back(word2[j]);
            j++;
        }
        
        while(i < m) {
            ans.push_back(word1[i]);
            i++;
        }
        while(j < n) {
            ans.push_back(word2[j]);
            j++;
        }
        
        return ans;
        
    }
};