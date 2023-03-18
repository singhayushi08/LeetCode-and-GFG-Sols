class Solution {
    
    
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        map<int, set<int>> mp; //key: stone and value: set containing options k-1, k, k+1

        set<int> s;
        for(int i=0; i<n; i++) {
            mp[stones[i]] = s;
        }
        
        mp[stones[0]].insert(1); //initially frog must jump 1 unit from 0th pos
        
        for(auto i: mp) {
            int curr_stone = i.first;
            set<int> jumps = mp[curr_stone]; 
            for(auto jump: jumps) { // iterate over the options
                int pos = curr_stone + jump;
                
                if(pos == stones[n-1]) return true;
                
                if(mp.find(pos) != mp.end()) { 
                    if(jump-1 > 0) { // we do not insert 0 as an option
                        mp[pos].insert(jump-1);
                    }
                    mp[pos].insert(jump);
                    mp[pos].insert(jump+1);
                }
            }
        }
        
        return false;
    }
};