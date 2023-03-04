class Solution {
public:
    int strStr(string haystack, string needle) {
        // Using sliding window
        // TC: O(m*k) coz in the worst case, we are iterating over every indx of haystack(size=m) and traversing a window of needle of size k. Ex: haystack = "aaaaab" and needle = "aab",  SC: O(1)
        int i = 0, j = 0;
        int m = haystack.size();
        int k = needle.size(); 
        int p = 0; //to traverse over needle 
        
        while(j < m) {
            if(haystack[j] == needle[p]) {
                p++;
            }
            if(j - i + 1 < k) {
                j++;
            }
            else if(j - i + 1 == k) { // window size hit
                if(p == k) return i; // found the word
                if(p != k) { // the word in this window is not our ans, slide the window
                    i++;
                    while(i < m && haystack[i] != needle[0]) {
                        i++;
                    }
                    if(i >= m) return -1; //ans does not exist
                    j = i;
                    p = 0;
                }
            }
        }
        
        return -1;
    }
};