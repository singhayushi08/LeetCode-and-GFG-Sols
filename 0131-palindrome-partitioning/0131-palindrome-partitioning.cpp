class Solution {
public:
    bool isPalindrome(string s, int start, int end) {
        while(start < end) {
            if(s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
    
    void helper(int idx, string &s, vector<string> &path, vector<vector<string>> &ans) {
        if(idx == s.size()) { // base case
            ans.push_back(path);
            return;
        }    
        
        // iterate over all possible partitions from idx to s.size()
        for(int i=idx; i<s.size(); i++) {
            if(isPalindrome(s, idx, i) == true) { //if substr from idx to i is palindrome, then only you can partition 
                path.push_back(s.substr(idx, i - idx + 1)); //take this palindrome substr in your path
                helper(i + 1, s, path, ans); //call rec on leftover string
                path.pop_back(); //remove partition while backtracking
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        // TC: O(2^n*k*n) where 2^n is for generating every substring, inserting k length substring in ans, and n for checking if it is a palindrome
        // SC: O(k*x + n) where x substrings of avg length k are inserted and n for rec stack space
        vector<vector<string>> ans;
        vector<string> path;
        helper(0, s, path, ans);
        return ans;
    }
};