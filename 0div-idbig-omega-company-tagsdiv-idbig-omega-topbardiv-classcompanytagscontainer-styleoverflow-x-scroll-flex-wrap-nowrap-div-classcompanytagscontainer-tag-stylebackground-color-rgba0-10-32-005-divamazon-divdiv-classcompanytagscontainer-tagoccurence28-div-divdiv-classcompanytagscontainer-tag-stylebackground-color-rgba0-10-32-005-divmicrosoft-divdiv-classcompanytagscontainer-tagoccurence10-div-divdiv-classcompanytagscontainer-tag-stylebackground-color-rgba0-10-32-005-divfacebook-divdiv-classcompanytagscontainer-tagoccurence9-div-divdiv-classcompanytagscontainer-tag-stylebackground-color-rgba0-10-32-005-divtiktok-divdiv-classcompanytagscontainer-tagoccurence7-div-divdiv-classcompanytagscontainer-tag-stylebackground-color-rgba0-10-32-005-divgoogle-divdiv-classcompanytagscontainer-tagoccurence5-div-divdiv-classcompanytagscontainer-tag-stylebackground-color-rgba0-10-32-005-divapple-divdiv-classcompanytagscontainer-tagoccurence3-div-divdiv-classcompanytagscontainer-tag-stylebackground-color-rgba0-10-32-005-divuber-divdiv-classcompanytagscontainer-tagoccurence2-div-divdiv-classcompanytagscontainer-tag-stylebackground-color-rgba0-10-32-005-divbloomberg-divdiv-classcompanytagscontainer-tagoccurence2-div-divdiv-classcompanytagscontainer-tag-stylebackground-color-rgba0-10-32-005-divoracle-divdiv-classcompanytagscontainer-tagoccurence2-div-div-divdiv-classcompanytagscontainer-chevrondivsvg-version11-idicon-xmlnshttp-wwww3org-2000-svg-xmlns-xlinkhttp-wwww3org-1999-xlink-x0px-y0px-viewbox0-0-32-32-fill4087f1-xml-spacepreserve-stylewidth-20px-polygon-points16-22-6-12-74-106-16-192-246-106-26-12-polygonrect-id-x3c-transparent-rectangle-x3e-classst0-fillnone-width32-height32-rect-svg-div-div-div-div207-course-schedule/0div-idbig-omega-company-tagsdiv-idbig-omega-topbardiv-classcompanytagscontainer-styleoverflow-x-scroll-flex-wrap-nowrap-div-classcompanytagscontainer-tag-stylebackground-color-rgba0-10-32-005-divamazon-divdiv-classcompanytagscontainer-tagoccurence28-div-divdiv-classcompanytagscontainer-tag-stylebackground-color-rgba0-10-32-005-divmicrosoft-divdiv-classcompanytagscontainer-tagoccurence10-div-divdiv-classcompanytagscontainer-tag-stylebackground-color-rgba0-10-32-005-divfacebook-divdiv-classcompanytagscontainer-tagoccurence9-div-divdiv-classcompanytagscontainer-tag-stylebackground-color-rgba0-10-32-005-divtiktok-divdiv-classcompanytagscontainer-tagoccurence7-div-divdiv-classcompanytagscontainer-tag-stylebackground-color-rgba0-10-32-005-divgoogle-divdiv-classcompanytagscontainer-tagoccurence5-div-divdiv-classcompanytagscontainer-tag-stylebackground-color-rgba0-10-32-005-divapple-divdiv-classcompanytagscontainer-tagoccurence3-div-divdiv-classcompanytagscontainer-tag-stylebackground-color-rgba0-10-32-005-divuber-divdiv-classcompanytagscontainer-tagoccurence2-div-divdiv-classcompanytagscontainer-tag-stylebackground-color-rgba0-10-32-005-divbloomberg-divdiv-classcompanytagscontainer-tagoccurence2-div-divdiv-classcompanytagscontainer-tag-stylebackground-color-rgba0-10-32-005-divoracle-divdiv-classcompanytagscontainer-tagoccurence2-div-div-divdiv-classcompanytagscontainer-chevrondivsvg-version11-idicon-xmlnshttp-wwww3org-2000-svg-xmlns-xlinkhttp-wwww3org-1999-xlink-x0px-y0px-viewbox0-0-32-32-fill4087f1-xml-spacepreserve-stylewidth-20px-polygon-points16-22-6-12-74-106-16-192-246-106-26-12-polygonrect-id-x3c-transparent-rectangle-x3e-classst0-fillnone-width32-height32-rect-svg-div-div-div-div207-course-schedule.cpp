class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // TC: O(V+E), SC: O(V+V) where V is no. of vertices and E is edges
        // do topo sort, if it works fine return true
        // else false
        
        vector<int> adj[numCourses];
        // if [ai,bi] => create adj list of edge btw bi->ai coz bi should appear first
        for(int i=0; i<prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            
            // v -> u
            adj[v].push_back(u);
        }
        
        // now do topo sort
        vector<int> indegree(numCourses,0);
        for(int i=0; i<numCourses; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }
        
        // put all nodes having indegree as 0 in queue
        queue<int> q;
        
        for(int i=0; i<numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        int cnt=0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            
            for(auto adjNode: adj[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
        
        if(cnt == numCourses) return true;
        return false;
    }
};