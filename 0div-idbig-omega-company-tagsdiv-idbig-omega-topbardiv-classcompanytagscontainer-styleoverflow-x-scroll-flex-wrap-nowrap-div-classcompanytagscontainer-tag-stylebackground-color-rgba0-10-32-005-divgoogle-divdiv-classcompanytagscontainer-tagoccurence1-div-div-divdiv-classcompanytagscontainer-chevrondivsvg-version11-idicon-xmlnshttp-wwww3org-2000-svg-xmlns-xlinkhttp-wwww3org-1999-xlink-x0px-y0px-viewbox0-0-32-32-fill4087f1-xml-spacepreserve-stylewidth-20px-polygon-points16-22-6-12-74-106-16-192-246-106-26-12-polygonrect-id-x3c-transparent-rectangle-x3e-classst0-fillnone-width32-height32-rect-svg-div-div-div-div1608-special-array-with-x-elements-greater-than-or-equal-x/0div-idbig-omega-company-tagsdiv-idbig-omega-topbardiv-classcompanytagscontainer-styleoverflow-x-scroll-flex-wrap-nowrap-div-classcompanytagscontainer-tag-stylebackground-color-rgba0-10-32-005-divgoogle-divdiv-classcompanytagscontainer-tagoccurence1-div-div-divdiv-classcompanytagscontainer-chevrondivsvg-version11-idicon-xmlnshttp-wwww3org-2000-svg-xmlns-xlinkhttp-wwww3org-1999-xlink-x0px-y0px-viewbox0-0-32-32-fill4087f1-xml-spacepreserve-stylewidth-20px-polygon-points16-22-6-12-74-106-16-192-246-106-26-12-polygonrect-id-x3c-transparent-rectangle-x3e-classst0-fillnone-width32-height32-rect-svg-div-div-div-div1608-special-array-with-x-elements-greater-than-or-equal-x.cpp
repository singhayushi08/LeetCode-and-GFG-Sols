class Solution {
public:
    int specialArray(vector<int>& nums) {
        // Brute force, TC: O(N^2), SC: O(1)
//         int ans = -1;
//         int maxi = 0;
//         for(int i=0; i<nums.size(); i++) {
//             maxi = max(maxi, nums[i]);
//         }
        
//         for(int num=1; num<=maxi; num++) {
//             int cnt = 0;
//             for(int i=0; i<nums.size(); i++) {
//                 if(nums[i] >= num) {
//                     cnt++;
//                 } 
//             }
//             if(cnt == num) return num;
//         }
        
//         return ans;
        
        // Sorting, TC: O(nlogn + n^2), SC: O(1)
        int ans = -1;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int num=1; num<=nums[n-1]; num++) {
            int cnt = 0;
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] >= num) {
                    cnt = (n-1)-i+1;
                    break;
                } 
            }
            if(cnt == num) return num;
        }
        
        return ans;
    }
};