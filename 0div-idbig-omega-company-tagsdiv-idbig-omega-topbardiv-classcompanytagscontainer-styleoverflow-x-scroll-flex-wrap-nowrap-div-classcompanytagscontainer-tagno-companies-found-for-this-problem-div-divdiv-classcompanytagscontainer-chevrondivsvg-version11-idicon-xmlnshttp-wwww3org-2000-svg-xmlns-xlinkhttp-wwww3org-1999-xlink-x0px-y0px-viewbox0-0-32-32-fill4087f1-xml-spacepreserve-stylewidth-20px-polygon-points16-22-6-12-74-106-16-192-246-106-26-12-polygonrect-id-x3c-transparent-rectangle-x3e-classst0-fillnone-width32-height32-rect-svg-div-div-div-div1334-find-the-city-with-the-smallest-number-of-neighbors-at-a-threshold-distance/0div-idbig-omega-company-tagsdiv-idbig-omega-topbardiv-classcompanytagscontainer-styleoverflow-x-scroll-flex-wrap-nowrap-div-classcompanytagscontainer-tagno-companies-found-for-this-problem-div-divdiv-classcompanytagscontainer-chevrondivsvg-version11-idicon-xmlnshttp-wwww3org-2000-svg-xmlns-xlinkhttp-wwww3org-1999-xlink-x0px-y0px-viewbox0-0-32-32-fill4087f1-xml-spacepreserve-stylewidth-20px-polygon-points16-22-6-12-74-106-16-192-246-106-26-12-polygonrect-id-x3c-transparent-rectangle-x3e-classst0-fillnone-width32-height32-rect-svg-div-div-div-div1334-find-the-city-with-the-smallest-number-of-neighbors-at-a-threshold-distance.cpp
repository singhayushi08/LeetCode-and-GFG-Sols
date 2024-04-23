class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // can be done using Floyd Warshall Algo or Dijktra's 
        // Done using Dijktra's here, tc: O(V*Elog(V)), SC: O(E+V)
        vector<pair<int,int>> adj[n];
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        int maxCnt = n+1;
        int city = -1;
        // using dijktra's algo to find shortest dist to every node in the graph
        // instead of source node, we will find dist from all nodes
        for(int i=0; i<n; i++) {
            int cnt = 0;

            // dijktra's algo
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({0,i});
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;

            while(!pq.empty()) {
                int node = pq.top().second;
                int w = pq.top().first;
                pq.pop();

                //traverse neighbours via adj matrix
                for(auto i: adj[node]) {
                    int adjNode = i.first;
                    int edW = i.second;
                    if(w + edW < dist[adjNode]) {
                        dist[adjNode] = w + edW;
                        pq.push({dist[adjNode], adjNode});
                    }
                }
            }
            
            // now check if there is any city with its shortest dist within the threshold given
            for(int i=0; i<n; i++) {
                if(dist[i] <= distanceThreshold) {
                    cnt++;
                }
            }
            if(cnt <= maxCnt) {
                maxCnt = cnt;
                city = i;
            }
        }
        
        return city;
    }
};