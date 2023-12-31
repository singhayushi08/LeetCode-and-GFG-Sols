class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // brute force, tc: O(N^2), sc: O(1)
        // int len = s.length();
        // int ans=0, res=0;
        // for(int i=0; i<len; i++) {
        //     for(int j=i+1; j<len; j++) {
        //         if(s[i] == s[j]) {
        //             ans = j-i-1;
        //             if(ans > res) res = ans;
        //         }
        //     }
        // }
        // return -1;
        
        // better , TC: O(n), sc: O(26+26)
//         int n = s.size();
//         vector<int> firstPos(26,-1);
//         vector<int> lastPos(26,-1);
        
//         for(int i=0; i<n; i++) {
//             int ch = s[i]-'a';
            
//             if(firstPos[ch] == -1) {
//                 firstPos[ch] = i;
//             } else {
//                 lastPos[ch] = i;
//             }
//         }
        
//         int ans = -1;
//         for(int i=0; i<26; i++) {
//             if(lastPos[i] != -1) lastPos[i] = lastPos[i]-firstPos[i]-1;
//             ans = max(ans,lastPos[i]);
//         }
//         return ans;
        
        // Using hashmap. TC: O(N), SC: O(26)
        unordered_map<char,int> firstPos; // to store first position of every char
        
        int ans = -1;
        for(int i=0;i<s.length(); i++) {
            if(firstPos.find(s[i]) != firstPos.end()) {
                ans = max(ans, i - firstPos[s[i]] - 1); 
            } else {
                firstPos[s[i]] = i;
            }
        }
        return ans;
    }
};