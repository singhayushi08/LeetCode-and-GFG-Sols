class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // Using adj list, TC: O(V+2E), SC: O(2E)
//         int n = edges.size()+1;
//         vector<int> adj[n+1];
//         for(int i=0; i<edges.size(); i++) {
//             int u = edges[i][0];
//             int v = edges[i][1];
            
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
        
//         for(int i=0; i<n+2; i++) {
//             if(adj[i].size() == n-1) return i;
//         }
        
//         return -1;
        
        // Using map, TC: O(nlogn), SC: O(n)
        int n = edges.size()+1;
        map<int,int> mp;
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            mp[u]++;
            mp[v]++;
        }
        
        for(auto i: mp) {
            if(i.second == n-1) return i.first;
        }
        
        return -1;
    }
};