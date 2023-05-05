class Solution {
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            return true;
        }
        return false;
    }
    
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int i=0, j=0;
        
        int max_vowel = INT_MIN, vowel_cnt = 0;
        while(j < n) {
            if(isVowel(s[j]) == true) {
                vowel_cnt++;
            }
            
            if(j-i+1 < k) {
                j++;
            } 
            else if(j-i+1 == k) { // window hit
                max_vowel = max(vowel_cnt, max_vowel);
                if(isVowel(s[i]) == true) {
                    vowel_cnt--;
                }
                i++;
                j++;
            }
        }
        
        return max_vowel;
    }
};