class DisjointSet {
    public:
        vector<int> parent, size;
    
        DisjointSet(int n) {
            parent.resize(n+1,0);
            size.resize(n+1,1);
            for(int i=0; i<=n; i++) {
                parent[i] = i;
            }
        }
    
        int getUltParent(int node) {
            if(parent[node] == node) {
                return node;
            }
            
            return parent[node] = getUltParent(parent[node]);
        }
    
        void unionBySize(int u, int v) {
            int ult_parent_u = getUltParent(u);
            int ult_parent_v = getUltParent(v);
            if(ult_parent_u == ult_parent_v) return;
            
            if(size[ult_parent_u] < size[ult_parent_v]) { //attach u to v
                parent[ult_parent_u] = ult_parent_v;
                size[ult_parent_v] += size[ult_parent_u];
            } else {
                parent[ult_parent_v] = ult_parent_u;
                size[ult_parent_u] += size[ult_parent_v];
            }
        }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Using Disjoint Set, TC: O(N+E) + O(E*4ɑ) + O(N*(ElogE + E)) 
        // SC: O(N+N+2N) for mergedMail,ans and 2N for parent,size array
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mp; //stores email, and the person it belongs to
        
        for(int i=0; i<n; i++) { //takes O(N+E)
            for(int j=1; j<accounts[i].size(); j++) {
                string email = accounts[i][j];
                int person = i;
                
                if(mp.find(email) != mp.end()) { //this email already exists, so merge curr account i with the one stored in the map
                    ds.unionBySize(person,mp[email]);
                } else {
                    mp[email] = person;
                }
            }
        }
        
        vector<string> mergedMail[n];
        for(auto it: mp) { //takes O(E*4ɑ)
            string email = it.first;
            int node = it.second;
            int ult_parent_node = ds.getUltParent(node);
            
            mergedMail[ult_parent_node].push_back(email);
        }
        
        vector<vector<string>> ans;
        for(int i=0; i<n; i++) { //takes O(N*(ELOGE+E))
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end()); //takes O(E LOG E)
            string person = accounts[i][0];
            vector<string> temp;
            temp.push_back(person);
            for(auto it: mergedMail[i]) { //takes O(E)
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};