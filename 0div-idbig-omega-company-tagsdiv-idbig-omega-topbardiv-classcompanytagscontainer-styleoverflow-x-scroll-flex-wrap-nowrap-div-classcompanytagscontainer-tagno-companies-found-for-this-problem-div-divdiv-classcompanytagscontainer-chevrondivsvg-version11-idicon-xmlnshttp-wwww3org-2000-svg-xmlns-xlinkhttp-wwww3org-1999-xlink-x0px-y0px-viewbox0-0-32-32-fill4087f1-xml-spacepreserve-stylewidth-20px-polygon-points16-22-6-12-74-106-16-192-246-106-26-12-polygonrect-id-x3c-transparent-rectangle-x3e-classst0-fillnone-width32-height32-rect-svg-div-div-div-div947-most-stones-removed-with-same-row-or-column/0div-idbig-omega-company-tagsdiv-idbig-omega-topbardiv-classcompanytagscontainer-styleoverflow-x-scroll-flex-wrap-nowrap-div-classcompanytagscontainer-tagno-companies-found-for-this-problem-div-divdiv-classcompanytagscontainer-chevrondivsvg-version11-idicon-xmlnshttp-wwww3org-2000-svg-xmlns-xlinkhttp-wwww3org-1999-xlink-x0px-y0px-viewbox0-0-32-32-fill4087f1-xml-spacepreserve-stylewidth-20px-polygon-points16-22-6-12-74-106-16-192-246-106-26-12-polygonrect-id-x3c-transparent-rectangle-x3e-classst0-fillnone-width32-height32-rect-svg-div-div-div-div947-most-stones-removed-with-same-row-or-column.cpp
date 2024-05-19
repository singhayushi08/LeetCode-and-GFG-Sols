class DisjointSet{
    public:
    
     vector<int> parent,size;
    
        DisjointSet(int n) {
            parent.resize(n+1,0);
            size.resize(n+1,1); //tells the no. of nodes in a component, each node is of size 1 individually
            for(int i=0; i<=n; i++) { //indivually, each node is its parent itself
                parent[i] = i;
            }
        }
        
        int getUltParent(int node) { // get root/ultimate parent of a node
            if(parent[node] == node) { //base case
                return node;
            }
            
            return parent[node] = getUltParent(parent[node]); //path compression is done here
        }
        
        void unionBySize(int u, int v) { // make an edge btw u and v
            int ult_pu = getUltParent(u);
            int ult_pv = getUltParent(v);
            if(ult_pu == ult_pv) return;
            
            if(size[ult_pu] < size[ult_pv]) { //attach u to v
                parent[ult_pu] = ult_pv;
                size[ult_pv] += size[ult_pu];
            } else { //size of ult_pv <= ult_pu, then attach v to u
                parent[ult_pv] = ult_pu;
                size[ult_pu] += size[ult_pv];
            }
            
            return;
        }
};

class Solution {
    void dfs(vector<vector<int>>& stones, int index, vector<int>& vis) {
        vis[index] = 1; //mark curr stone as visited
        
        // check in the stones if there is any other stone is same row or same column which is not visited
        for(int i=0; i<stones.size(); i++) {
            int row = stones[index][0];
            int col = stones[index][1];
            
            if(vis[i] == 0 && (stones[i][0] == row || stones[i][1] == col)) {
                dfs(stones, i, vis);
            }
        }
        
        return;
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        // Using graph DFS, TC: O(n^2), SC: O(n)
        // int n = stones.size();
//         vector<int> vis(n,0); //stores if curr stone (i,j) of stones array is visited or not
        
//         int totalComponents = 0;
//         for(int i=0; i<n; i++) {
//             if(vis[i] == 0) {
//                 dfs(stones, i, vis);
//                 totalComponents++;
//             }
//         }
        
//         return n - totalComponents;
        
        // Using DSU, TC: O(n+ n*4ahlpa + n*4alpha), SC: O(2n+n)
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(int i=0; i<n; i++) {
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }
        
        DisjointSet ds(maxRow + maxCol + 1);
        
        unordered_map<int,int> nodeStones; //stores nodes which are stones
        for(auto it: stones) {
            int row = it[0];
            int col = it[1] + maxRow + 1;
            
            ds.unionBySize(row, col);
            nodeStones[row] = 1;
            nodeStones[col] = 1;
        }
        
        int totalComponents = 0;
        //now find unique parents of stone nodes
        for(auto it: nodeStones) {
            if(ds.getUltParent(it.first) == it.first) {
                totalComponents++;
            }
        }
        
        return n - totalComponents;
    }
};