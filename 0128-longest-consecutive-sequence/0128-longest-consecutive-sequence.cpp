class Solution {
    bool search(vector<int>& nums, int element) {
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == element) return true;
        }
        return false;
    }
    
public:
    int longestConsecutive(vector<int>& nums) {
        // Brute force- TC: O(n^2), SC: O(1)
        // int ans = 0;
        // for(int i=0; i<nums.size(); i++) {
        //     int curr = nums[i];
        //     int curr_len = 1;
        //     while(search(nums, curr+1)==true) {
        //         curr += 1;
        //         curr_len += 1;
        //     }
        //     ans = max(curr_len, ans);
        // }
        // return ans;
        
        // Better, TC: O(nlogn), SC: O(1)
//         int n = nums.size();
//         if(n == 0 || n == 1) return n;
//         sort(nums.begin(), nums.end());
//         int prev = nums[0], ans = 1;
//         int curr_len = 1;
//         for(int i=1; i<n; i++) {
//             if(nums[i] == prev + 1) {
//                 curr_len += 1;
//                 prev = nums[i];
//                 ans = max(curr_len, ans);
//             }
//             else if(nums[i] == prev) {
//                 continue;
//             }
//             else if(nums[i] != prev + 1) { // 1 2 3 4 100 101 102
//                 curr_len = 1; //reset 
//                 prev = nums[i];
//             }
//         }
        
//         return ans;
        
        // Using set, TC: O(n), SC: O(n) avoiding collision
        unordered_set<int> s;
        for(int i=0; i<nums.size(); i++) {
            s.insert(nums[i]);
        }
        
        int ans = 0;
        for(auto i: s) {
            int curr = i;
            if(s.find(curr-1) == s.end()) {
                int curr_len = 1;
                while(s.find(curr+1) != s.end()) {
                    curr += 1;
                    curr_len += 1;
                }
                ans = max(ans, curr_len);
            }
        }
        
        return ans;
        
        
    }
};