class Solution {
    bool isPalindrome(string s, int i) { //recursive code gives tle
        // if(i >= s.size()/2) { // base case
        //     return true;
        // }
        // if(s[i] != s[s.size()-i-1]) {
        //     return false;
        // }
        // return isPalindrome(s, i+1);

        for(int i=0; i<s.size()/2; i++) {
            if(s[i] != s[s.length()-i-1]) {
                return false;
            }
        }
        return true;
    }

public:
    bool isPalindrome(string s) {
        // TC: O(N), SC: O(N) for rec stack space
        // 1. convert into lowercase, ASCII value of A is 65 and a is 97
        for(int i=0; i<s.length(); i++) {
            if(s[i] >= 'A' && s[i] <= 'Z') { 
                s[i] = s[i] + 32; //add the diff to make it lowercase, 97-65 = 32
            }
        }
        cout<<s<<endl;
        
        // 2. remove everything except letters, ASCII value of 0 is 48, 9 is 57
        string str = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9') {
                str.push_back(s[i]);
            }
        }
        cout<<str<<endl;

        // 3. noew check if str is palindrome or not
        return isPalindrome(str, 0);
    }
};