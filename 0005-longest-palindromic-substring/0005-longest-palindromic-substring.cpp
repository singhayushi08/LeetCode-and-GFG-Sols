class Solution {
    int expandFromCentre(string s, int i, int j) {
        while(i>=0 && j<s.size() && s[i]==s[j]) {
            i--;
            j++;
        }
        return j-i-1;
    }
  
public:
    string longestPalindrome(string s) {
        // DP Tabulation using Longest Common substring approach
//         string t = s;
//         reverse(t.begin(), t.end());
//         int n = s.size();
//         int m = t.size();
//         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
//         for(int j=0; j<=m; j++) dp[0][j] = 0;
//         for(int i=0; i<=n; i++) dp[i][0] = 0;
        
//         int len = 0, x = 0, y = 0;
//         for(int i=1; i<=n; i++) {
//             for(int j=1; j<=m; j++) {
//                 if(s[i-1] == t[j-1]) {
//                     dp[i][j] = 1 + dp[i-1][j-1];
//                     if(dp[i][j] > len && i-dp[i][j] == n-j) {
//                         len = dp[i][j];
//                         x = i;
//                         y = j;
//                         cout<<"len "<<len<<" updated at x: "<<x<<" , y: "<<y<<endl;
//                     }
//                 } else {
//                     dp[i][j] = 0;
//                 }
//             }
//         }
        
//         for(int i=0; i<=n; i++) {
//             for(int j=0; j<=m; j++) {
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
//         string res = "";
//         while(dp[x][y] != 0) {
//             res.push_back(s[x-1]);
//             x--;
//             y--;
//         }
//         reverse(res.begin(), res.end());
        
//         return res;
        
        // Expand from center, TC: O(n^2), SC: O(1)
        int start = 0;
        int end = 0;
        for(int i=0; i<s.size(); i++) {
            int len1 = expandFromCentre(s, i, i); //for odd length
            int len2 = expandFromCentre(s, i, i+1); //for even length 
            int maxLength = max(len1, len2);
            int currLength = end-start+1;
            if(maxLength > currLength) {
                start = i-(maxLength-1)/2;
                end = i + (maxLength)/2;
            }
        }
        
        return s.substr(start, end-start+1);
        
    }
};