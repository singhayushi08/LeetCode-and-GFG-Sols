class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Using map, TC: O(n), SC: O(n)
        // unordered_map<int,int> mp;
        // for(auto i: nums) {
        //     mp[i]++;
        // }
        // for(auto it: mp) {
        //     if(it.second >= 2) return true;
        // }
        // return false;
        
        // Using set, TC: O(nlogn), SC: O(1)
        int n = nums.size();
        set<int> s;
        for(auto i: nums) {
            s.insert(i);
        }
        int m = s.size();
        if(m == n) return false;
        return true;
    }
};