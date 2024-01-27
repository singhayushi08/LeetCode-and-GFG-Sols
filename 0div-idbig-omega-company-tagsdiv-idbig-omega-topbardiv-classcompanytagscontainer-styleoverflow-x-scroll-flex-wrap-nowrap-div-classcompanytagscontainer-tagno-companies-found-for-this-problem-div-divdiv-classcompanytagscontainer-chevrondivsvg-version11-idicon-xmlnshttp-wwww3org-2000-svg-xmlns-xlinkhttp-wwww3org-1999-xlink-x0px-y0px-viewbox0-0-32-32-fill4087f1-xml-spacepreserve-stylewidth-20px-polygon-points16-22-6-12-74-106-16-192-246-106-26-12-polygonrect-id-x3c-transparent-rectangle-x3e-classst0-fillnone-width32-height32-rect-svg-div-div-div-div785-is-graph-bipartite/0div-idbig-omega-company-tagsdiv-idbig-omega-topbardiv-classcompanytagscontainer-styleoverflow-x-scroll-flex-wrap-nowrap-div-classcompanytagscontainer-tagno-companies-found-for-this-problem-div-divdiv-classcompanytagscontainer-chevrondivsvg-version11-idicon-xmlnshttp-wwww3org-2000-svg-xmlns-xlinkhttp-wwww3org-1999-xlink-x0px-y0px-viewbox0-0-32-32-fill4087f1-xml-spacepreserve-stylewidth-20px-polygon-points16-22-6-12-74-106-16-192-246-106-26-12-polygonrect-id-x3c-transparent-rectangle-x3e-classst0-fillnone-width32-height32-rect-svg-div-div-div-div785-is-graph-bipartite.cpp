class Solution {
    bool check(int startNode, int V, vector<vector<int>>& graph, vector<int> &vis) {
        queue<int> q; 
        q.push(startNode); 
        vis[startNode] = 0; // mark this at set A
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            // visit neighbours of node
            for(auto adjacentNode: graph[node]) {
                if(vis[adjacentNode] == -1) { // if not visited, partition adjacent Node with opposite set of node
                    q.push(adjacentNode);
                    vis[adjacentNode] = (vis[node] == 0) ? 1 : 0; // if node is set A i.e. 1, adjacent node will be of set B i.e. 0
                }
                else { // already visited and colored, then check if node and adjacent node have same set
                    if(vis[adjacentNode] == vis[node]) return false;
                }
            }
        }
        
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) { 
        // Graph BFS, TC: O(V + 2E), SC: O(V + V)
        int V = graph.size();
        vector<int> vis(V,-1); // stores the set of visited nodes
        
        for(int i=0; i<V; i++) {
            if(vis[i] == -1) {
                if(check(i,V,graph,vis) == false) return false;
            }
        }
        
        return true;
    }
};