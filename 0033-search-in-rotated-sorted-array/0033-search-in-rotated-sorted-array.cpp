class Solution {
    
    int findPivot(vector<int> &nums, int n) { // returns index of pivot/min element
        if(n == 1) return 0;
        if(nums[0] < nums[n-1]) return 0;  // array is sorted, no rotations (min element is at 0 index)
        int s = 0, e = n-1;
        while(s < e) {
            int mid = s + (e-s)/2;
            if(nums[mid] >= nums[0]) { // mid lies on line 1
                s = mid+1;
            } else { 
                e = mid;
            }
        }
        return s;
    }
    
    int binarySearch(vector<int> &nums, int s, int e, int target) {
        int mid;
        while(s <= e) {
            mid = s + (e-s)/2;
            if(nums[mid] == target) {
                return mid;
            } 
            else if(nums[mid] < target) {
                s = mid+1;
            } 
            else {
                e = mid-1;
            }
        }
        
        return -1;
    }
    
public:
    int search(vector<int>& nums, int target) {
        // Binary Search-- Tc: O(logN+logN) => O(logN), SC: O(1)
        // 1. find pivot element i.e. min element
        // 2. compare pivot,target and find which line does the target lies on and apply BS on that line
        
        int n = nums.size();
//         int pivotIndex = findPivot(nums, n);
//         if(target >= nums[pivotIndex] && target <= nums[n-1]) {
//             return binarySearch(nums, pivotIndex, n-1, target);
//         } else {
//             return binarySearch(nums, 0, pivotIndex-1, target);
//         }
//         return -1; // not found
        
        //  Striver's Approach, TC: O(logN), SC: O(1)
        int low = 0, high = n-1;
        
        while(low <= high) {
            int mid = (low + high)/2;
            if(nums[mid] == target) return mid;
            
            // check if left part is sorted
            if(nums[low] <= nums[mid]) {
                // check if target exists here
                if(target >= nums[low] && target <= nums[mid]) {
                    high = mid-1;
                }
                else {
                    low = mid+1;
                }
            }
            // else right part is sorted
            else {
                if(target >= nums[mid] && target <= nums[high]) {
                    low = mid+1;
                }
                else {
                    high = mid-1;
                }
            }
        }
        
        return -1;
        
    }
};