class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // Binary Search, TC: O(logN), SC: O(1)
        int n = nums.size();
        int low = 0, high = n-1;
        
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target) return true;
            
            // in case of duplicates
            if(nums[mid] == nums[low] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }
            
            // check if left part is sorted
            if(nums[low] <= nums[mid]) {
                if(target >= nums[low] && target < nums[mid]) { // check if target exists here
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else { // else right part is sorted
                if(target > nums[mid] && target <= nums[high]) { // check if target exists here
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }
        
        return false;
    }
};