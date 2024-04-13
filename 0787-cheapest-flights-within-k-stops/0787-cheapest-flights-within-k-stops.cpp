class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // TC: O(E) where E is the no. of edges = O(n), SC: O(E+V) for adj list, dist array & queue
        // create adj list 
        vector<pair<int,int>> adj[n];
        for(auto it: flights) {
            int u  = it[0];
            int v = it[1];
            int w = it[2];
            
            adj[u].push_back({v,w}); //directed adj list
        }
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0; //cost taken to reach src from src is 0
        queue<pair<int,pair<int,int>>> q; //{stops, {node, cost}}
        q.push({0,{src,0}});
        
        while(!q.empty()) {
            pair<int,pair<int,int>> it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if(stops > k) break;
            
            //traverse adj nodes of node
            for(auto iter: adj[node]) {
                int adjNode = iter.first;
                int adjCost = iter.second;
                
                if(cost + adjCost < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + adjCost;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }
        
        if(dist[dst] == INT_MAX) return -1; //no route to reach dst
        return dist[dst];
    }
};