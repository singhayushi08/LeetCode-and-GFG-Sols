class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        map<int,int> mp;
        for(int i=0; i<jewels.size(); i++) {
            mp[jewels[i]] = 1;
        }
        
        int cnt = 0;
        for(int i=0; i<stones.size(); i++) {
            if(mp.find(stones[i]) != mp.end()) cnt++;
        }
        
        return cnt;
    }
};