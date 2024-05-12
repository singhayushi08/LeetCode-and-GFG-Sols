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
public:
    int largestIsland(vector<vector<int>>& grid) {
        // Using Disjoint Set, TC: O(N^2), SC: O(N^2)
        int n = grid.size();
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        DisjointSet ds(n*n);
        
        // create dsu
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) continue;
                
                // check neighbour nodes & connect if it adjnode is 1
                for(int k=0; k<4; k++) {
                    int nrow = i + delrow[k];
                    int ncol = j + delcol[k];
                    
                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol < n) {
                        if(grid[nrow][ncol] == 1) {
                            int nodeNo = i * n + j;
                            int adjNodeNo = nrow * n + ncol;
                            
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) continue;
                unordered_set<int> s; // this set stores the root of adjnodes to avoid getting two adj nodes that belong to the same component added up in the sum twice
                
                // check neighbour nodes 
                for(int k=0; k<4; k++) {
                    int nrow = i + delrow[k];
                    int ncol = j + delcol[k];
                    
                    if(nrow >= 0 && nrow < n && ncol >=0 && ncol < n) {
                        if(grid[nrow][ncol] == 1) {
                            int adjNodeNo = nrow * n + ncol;
                            s.insert(ds.getUltParent(adjNodeNo));
                        }
                    }
                }
                
                int cnt = 0;
                for(auto it: s) {
                    cnt += ds.size[it];
                }
                
                ans = max(ans, cnt + 1);
            }
        }
        
        // in case there is no cell with 0 in the matrix, then the ans will be the size[0]
        for(int cellNo = 0; cellNo<n*n; cellNo++) {
            ans = max(ans, ds.size[ds.getUltParent(cellNo)]);
        }
        
        return ans;
    }
};