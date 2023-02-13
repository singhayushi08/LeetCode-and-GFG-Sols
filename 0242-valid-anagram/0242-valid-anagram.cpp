class Solution {
public:
    bool isAnagram(string s, string t) {
        // if both strings are not of same length, then it can never be an anagram
        if(s.length() != t.length()) { 
            return false;
        }
        
        // strings are of same length, so it can be an anagram
        // anagram condition =>  freq count of each char in both strings are equal
        int freq[26] = {0}; 
        
        for(int i=0; i<s.length(); i++) {
            freq[s[i]-'a']++; // whenever you see a char in string s, increment its count
            freq[t[i]-'a']--; // whenever you see a char in string t, decrement its count
        }
        
        // check the freq count of each char in freq[], if all are 0 then it is valid anagram
        for(int i=0; i<26; i++) {
            if(freq[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};