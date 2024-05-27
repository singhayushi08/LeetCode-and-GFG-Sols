class Solution {
    int getFirstIndex(vector<int>& nums, int val) {
        int low = 0;
        int high = nums.size()-1;
        int index = nums.size();
        
        while(low <= high) {
            int mid = (low+high)/2;
            if(nums[mid] >= val) {
                index = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return index;
    }
public:
    int specialArray(vector<int>& nums) {
        // Brute force, TC: O(N^2), SC: O(1)
//         int ans = -1;
        
//         for(int num=1; num<=nums.size(); num++) {
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
//         int ans = -1;
//         int n = nums.size();
//         sort(nums.begin(), nums.end());

//         for(int num=1; num<=n; num++) {
//             int cnt = 0;
//             for(int i=0; i<nums.size(); i++) {
//                 if(nums[i] >= num) {
//                     cnt = (n-1)-i+1;
//                     break;
//                 } 
//             }
//             if(cnt == num) return num;
//         }
        
//         return ans;
        
        // Sorting + binary search, TC: O(nlogn), SC: O(1)
        int ans = -1;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=1; i<=n; i++) {
            int k = getFirstIndex(nums,i); //first index where i or greater than i is present in nums
            if(n-k == i) {
                return i;
            }
        }
        
        return -1;
    }
};