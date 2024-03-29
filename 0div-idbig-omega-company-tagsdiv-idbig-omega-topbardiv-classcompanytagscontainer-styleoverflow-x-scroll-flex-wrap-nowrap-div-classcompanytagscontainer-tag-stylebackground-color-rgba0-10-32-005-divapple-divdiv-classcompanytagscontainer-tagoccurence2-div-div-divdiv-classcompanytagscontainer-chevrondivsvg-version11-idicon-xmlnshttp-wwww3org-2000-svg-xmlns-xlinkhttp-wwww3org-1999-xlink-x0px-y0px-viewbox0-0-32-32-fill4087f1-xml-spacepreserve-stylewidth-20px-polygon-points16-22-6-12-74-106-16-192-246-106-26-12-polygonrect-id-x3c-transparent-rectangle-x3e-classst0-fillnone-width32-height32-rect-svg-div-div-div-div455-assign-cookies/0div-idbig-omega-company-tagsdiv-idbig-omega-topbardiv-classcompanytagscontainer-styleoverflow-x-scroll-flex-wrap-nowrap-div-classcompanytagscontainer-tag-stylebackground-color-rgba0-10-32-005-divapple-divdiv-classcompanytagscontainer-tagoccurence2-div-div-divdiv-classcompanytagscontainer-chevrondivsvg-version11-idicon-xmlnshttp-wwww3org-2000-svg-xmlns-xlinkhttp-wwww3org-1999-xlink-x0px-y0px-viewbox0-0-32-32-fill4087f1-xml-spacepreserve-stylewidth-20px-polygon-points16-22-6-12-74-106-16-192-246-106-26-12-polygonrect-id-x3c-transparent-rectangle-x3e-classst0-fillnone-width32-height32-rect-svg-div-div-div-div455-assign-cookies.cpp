class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // brute, TC: O(N^2), SC: O(1)
        // int ans=0;
        // for(int i=0; i<g.size(); i++) {
        //     for(int j=0; j<s.size(); j++) {
        //         if(s[j] >= g[i]) {
        //             ans++; 
        //             break;
        //         }
        //     }
        // }
        // return ans;
        
        // sorting, TC: O(nlogn), SC: O(1)
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0,ans=0;
        
        while(i<g.size() && j<s.size()) {
            if(g[i]<=s[j]) {
                ans++;
                i++; j++;
            } else {
                j++;
            }
        }
        return ans;
    }
};