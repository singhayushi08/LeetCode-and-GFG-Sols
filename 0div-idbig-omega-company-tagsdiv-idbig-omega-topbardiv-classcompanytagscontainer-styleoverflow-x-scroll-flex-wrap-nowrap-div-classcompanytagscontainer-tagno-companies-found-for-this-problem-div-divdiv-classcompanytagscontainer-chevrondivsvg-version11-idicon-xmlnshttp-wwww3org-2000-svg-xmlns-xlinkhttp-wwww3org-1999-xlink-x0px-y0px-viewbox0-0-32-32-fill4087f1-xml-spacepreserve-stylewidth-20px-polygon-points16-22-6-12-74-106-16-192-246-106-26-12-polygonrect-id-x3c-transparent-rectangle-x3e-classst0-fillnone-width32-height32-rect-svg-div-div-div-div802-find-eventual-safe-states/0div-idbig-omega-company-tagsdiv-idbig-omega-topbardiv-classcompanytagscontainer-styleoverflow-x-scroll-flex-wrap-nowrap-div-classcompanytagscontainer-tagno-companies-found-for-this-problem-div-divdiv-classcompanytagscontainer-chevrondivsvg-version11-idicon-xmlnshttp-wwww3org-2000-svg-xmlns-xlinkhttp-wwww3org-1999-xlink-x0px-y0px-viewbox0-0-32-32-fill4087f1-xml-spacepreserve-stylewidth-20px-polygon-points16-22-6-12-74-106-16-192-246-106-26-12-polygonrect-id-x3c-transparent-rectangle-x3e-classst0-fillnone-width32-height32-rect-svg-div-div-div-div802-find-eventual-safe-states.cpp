class Solution {
    bool dfs(int node,  vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto adjacentNode: graph[node]) {
            if(vis[adjacentNode] == 0) {
                check[adjacentNode] = 0;
                if(dfs(adjacentNode, graph, vis, pathVis, check) == true) return true;
            } else if(pathVis[adjacentNode] == 1) { // node already visited in curr path, cycle exists
                check[adjacentNode] = 0;
                return true;
            }
        }
        
        // coming here means this node has explored all paths starting from node and did not find a cycle in any path
        // meaning this node is safe node
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // Graph DFS, TC: O(2V + (V+E)), SC: O(3V)
        int V = graph.size(); // no. of vertices/nodes
        vector<int> safeNodes;
        vector<int> vis(V,0);
        vector<int> pathVis(V,0);
        vector<int> check(V,0);
        
        for(int i=0; i<V; i++) {
            if(vis[i] == 0) {
                dfs(i,graph,vis,pathVis,check);
            }
        }
        
        for(int i=0; i<V; i++) {
            if(check[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};