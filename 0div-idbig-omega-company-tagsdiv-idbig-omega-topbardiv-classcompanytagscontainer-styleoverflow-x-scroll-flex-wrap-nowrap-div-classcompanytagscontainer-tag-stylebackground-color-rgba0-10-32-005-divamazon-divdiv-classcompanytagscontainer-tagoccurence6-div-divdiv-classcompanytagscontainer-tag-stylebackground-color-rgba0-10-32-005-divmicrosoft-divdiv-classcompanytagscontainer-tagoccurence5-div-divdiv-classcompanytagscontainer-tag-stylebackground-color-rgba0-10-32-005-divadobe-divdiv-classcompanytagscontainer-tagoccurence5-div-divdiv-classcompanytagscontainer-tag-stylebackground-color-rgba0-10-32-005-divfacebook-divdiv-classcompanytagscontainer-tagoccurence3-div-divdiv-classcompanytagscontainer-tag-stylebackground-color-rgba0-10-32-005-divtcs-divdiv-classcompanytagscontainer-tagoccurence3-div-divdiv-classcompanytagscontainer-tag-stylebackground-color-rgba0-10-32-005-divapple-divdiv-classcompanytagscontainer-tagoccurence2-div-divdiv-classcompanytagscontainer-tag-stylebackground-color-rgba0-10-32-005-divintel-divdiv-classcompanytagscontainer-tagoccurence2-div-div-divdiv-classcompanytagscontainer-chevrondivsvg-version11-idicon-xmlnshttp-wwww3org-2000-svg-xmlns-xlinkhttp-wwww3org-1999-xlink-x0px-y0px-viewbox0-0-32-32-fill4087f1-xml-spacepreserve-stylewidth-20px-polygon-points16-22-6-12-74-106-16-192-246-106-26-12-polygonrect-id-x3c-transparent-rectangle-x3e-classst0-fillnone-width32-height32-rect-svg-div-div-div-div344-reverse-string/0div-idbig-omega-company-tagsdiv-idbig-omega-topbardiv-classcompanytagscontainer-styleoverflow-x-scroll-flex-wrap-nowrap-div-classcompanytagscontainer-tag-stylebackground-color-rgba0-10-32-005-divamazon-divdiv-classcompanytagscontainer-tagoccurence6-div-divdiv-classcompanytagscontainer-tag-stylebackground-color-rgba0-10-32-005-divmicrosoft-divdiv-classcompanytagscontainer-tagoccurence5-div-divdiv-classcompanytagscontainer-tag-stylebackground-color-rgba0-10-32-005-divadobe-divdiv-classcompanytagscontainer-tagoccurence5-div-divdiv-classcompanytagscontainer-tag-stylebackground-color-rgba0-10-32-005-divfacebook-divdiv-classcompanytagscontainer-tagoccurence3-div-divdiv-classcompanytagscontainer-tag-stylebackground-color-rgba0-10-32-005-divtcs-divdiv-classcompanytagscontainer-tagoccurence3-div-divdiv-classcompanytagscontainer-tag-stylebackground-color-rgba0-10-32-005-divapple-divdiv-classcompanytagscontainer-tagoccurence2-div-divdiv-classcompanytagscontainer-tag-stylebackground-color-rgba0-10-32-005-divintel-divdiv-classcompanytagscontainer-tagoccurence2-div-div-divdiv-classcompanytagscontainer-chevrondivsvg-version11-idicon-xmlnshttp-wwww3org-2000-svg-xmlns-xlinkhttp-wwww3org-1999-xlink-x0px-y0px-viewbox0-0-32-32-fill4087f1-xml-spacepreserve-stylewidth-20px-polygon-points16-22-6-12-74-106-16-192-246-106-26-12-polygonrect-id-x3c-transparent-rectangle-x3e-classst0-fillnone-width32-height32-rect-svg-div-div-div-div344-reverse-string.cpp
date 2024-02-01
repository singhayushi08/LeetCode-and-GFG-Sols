class Solution {
    void helper(int start, int end, vector<char>& s) {
        if(start >= end) return;
        
        // swap start & end element
        int temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        
        // call rec on smaller problem
        helper(start+1, end-1, s);
    }
    
public:
    void reverseString(vector<char>& s) {
        // iteratively
       // int n = s.size();
//         int i=0, j=n-1;
        
//         while(i <= j) {
//             char temp = s[i];
//             s[i] = s[j];
//             s[j] = temp;
//             i++; j--;
//         }
        
//         return;
        
        // recursively
        helper(0, s.size()-1, s);
    }
};