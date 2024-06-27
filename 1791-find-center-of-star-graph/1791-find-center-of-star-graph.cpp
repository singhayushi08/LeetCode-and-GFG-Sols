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
        
        // Using map, TC: O(n), SC: O(n)
//         int n = edges.size()+1;
//         unordered_map<int,int> mp; //stores degree of each node
//         for(int i=0; i<edges.size(); i++) {
//             int u = edges[i][0];
//             int v = edges[i][1];
            
//             mp[u]++;
//             mp[v]++;
//         }
        
//         for(auto i: mp) {
//             if(i.second == n-1) return i.first;
//         }
        
//         return -1;
        
        // Most optimized, TC: O(1), SC: O(1)
        // In a star graph, the center node will be common node in all the edges
        // so compare any two edges in the graph and the common node btw them is the center for sure
        vector<int> firstEdge = edges[0];
        vector<int> secondEdge = edges[1];
        
        return (firstEdge[0] == secondEdge[0] || firstEdge[0] == secondEdge[1]) ? firstEdge[0] : firstEdge[1];
    }
};