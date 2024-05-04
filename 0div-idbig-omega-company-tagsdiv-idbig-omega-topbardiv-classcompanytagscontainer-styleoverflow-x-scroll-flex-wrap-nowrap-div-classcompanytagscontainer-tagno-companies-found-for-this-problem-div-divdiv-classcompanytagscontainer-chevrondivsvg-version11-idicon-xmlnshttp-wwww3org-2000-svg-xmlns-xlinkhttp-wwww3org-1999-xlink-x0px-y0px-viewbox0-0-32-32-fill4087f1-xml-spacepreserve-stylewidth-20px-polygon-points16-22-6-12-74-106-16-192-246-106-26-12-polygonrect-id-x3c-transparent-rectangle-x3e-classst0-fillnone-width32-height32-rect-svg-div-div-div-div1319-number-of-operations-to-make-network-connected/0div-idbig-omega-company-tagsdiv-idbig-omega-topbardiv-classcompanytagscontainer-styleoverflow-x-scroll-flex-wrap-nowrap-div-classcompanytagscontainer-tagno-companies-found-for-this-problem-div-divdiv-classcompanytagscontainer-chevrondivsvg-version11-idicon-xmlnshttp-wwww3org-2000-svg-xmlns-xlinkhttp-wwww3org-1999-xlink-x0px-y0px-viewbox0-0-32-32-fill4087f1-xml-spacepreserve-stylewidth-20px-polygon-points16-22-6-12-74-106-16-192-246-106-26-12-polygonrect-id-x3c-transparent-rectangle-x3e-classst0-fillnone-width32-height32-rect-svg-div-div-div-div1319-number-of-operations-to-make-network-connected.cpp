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
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Using Disjoint set, TC: O(V+E), SC: O(2V)
        DisjointSet ds(n);
        int extraEdges=0;
        
        for(auto it: connections) {
            int u = it[0];
            int v = it[1];
                
            if(ds.getUltParent(u) != ds.getUltParent(v)) {
                ds.unionBySize(u,v);
            } else {
                extraEdges++;
            }
        }
        
        int no_of_comp = 0;
        for(int i=0; i<n; i++) {
            if(ds.parent[i] == i) {
                no_of_comp++;
            }
        }
        
        int ans = no_of_comp-1; //required no. of edges to connect all components
        if(extraEdges >= ans) return ans;
        return -1;
    }
};