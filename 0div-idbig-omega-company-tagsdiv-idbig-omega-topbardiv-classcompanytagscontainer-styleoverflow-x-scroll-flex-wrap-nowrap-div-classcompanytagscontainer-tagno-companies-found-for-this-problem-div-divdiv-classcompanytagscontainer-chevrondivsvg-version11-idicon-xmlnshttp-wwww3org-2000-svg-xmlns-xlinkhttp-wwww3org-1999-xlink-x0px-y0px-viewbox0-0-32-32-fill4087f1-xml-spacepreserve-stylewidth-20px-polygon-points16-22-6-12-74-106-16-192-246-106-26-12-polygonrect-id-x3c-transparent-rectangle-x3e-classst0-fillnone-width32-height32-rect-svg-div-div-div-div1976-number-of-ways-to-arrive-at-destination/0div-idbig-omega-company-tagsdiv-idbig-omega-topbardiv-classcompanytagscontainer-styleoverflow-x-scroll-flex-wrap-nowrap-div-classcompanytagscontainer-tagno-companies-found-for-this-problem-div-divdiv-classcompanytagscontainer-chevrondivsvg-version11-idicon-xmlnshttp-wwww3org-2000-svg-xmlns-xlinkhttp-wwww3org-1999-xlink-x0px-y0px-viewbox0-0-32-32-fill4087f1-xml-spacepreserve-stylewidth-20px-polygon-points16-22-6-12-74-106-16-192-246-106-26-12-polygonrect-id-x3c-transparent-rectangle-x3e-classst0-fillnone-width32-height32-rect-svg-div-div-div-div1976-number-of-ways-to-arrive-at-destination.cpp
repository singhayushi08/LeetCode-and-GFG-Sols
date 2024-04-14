class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Simple Dijktra's BFS Algo by keeping track of no. of ways to reach a node with shortest distance
        
        //create undirected adj list
        vector<pair<long long,long long>> adj[n];
        for(auto it: roads) {
            long long u = it[0];
            long long v = it[1];
            long long w = it[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq; //{dist, node}
        pq.push({0,0});
        
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;
        vector<long long> ways(n, 0); //stores no. of ways to reach node i
        ways[0] = 1; //you can reach node 0 in only 1 way
        int mod = 1e9 + 7;
        
        while(!pq.empty()) {
            long long node = pq.top().second;
            long long time = pq.top().first;
            pq.pop();
            
            //traverse neighbour nodes
            for(auto i: adj[node]) {
                long long adjNode = i.first;
                long long adjTime = i.second; //as time given in question can be at max 1e9

                if(time + adjTime < dist[adjNode]) { //first time coming to adjnode with the shortest distance
                    dist[adjNode] = time + adjTime;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if(time + adjTime == dist[adjNode]) { //already reached adjnode with shortest distance
                    ways[adjNode]  = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        
        return ways[n-1]%mod;
    }
};
