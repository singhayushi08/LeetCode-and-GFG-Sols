class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        // Using hashmap, TC: O(N), SC: O(N)
        // greedy approach coz we are always trying to take 3 rounds at once instead of 2 to get the min rounds
        // https://www.youtube.com/watch?v=IIalYnjpAJA
        unordered_map<int,int> mp; 
        for(int i=0; i<tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        
        int round = 0;
        // every no. n can be represented in terms of 3k or 3k+1 or 3k+2
        // 3k => 3,6,9,12 etc 
        // 3k+1 => 1,4,7,10 etc
        // 3k+2 => 5,8,11 etc
        for(auto i: mp) {
            int freq = i.second;
            if(freq == 1) { //not possible
                return -1;
            }
            else if(freq == 2) {
                round++;
            }
            else { 
                if(freq % 3 == 0) { //if freq is in form of 3k
                    round += freq/3;
                }
                else { //if freq is in form of 3k+1 or 3k+2 (like 10 => 3+3+2+2 so 4 rounds)
                    round += (freq/3) + 1;
                }
            }
        }
        
        return round;
    }
};