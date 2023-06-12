class Solution {
public:
    bool isAnagram(string s, string t) {
        // TC: O(nlogn), SC: O(1)
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
        
        // optimal: TC: O(n), SC: O(26)
        if(s.size() != t.size()) return false;
        
        int freq[26] = {0}; // for 26 characters
        
        for(int i=0; i<s.size(); i++) {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        
        for(int i=0; i<26; i++) {
            if(freq[i] != 0) return false;
        }
        
        return true;
    }
};