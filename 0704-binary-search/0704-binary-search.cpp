class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Binary Search, TC: O(logN), SC: O(1)
        int n = nums.size();
        int s = 0, e = n-1;
        while(s <= e) {
            int mid = s + (e-s)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) { // go right
                s = mid+1;
            } 
            else { // go left
                e = mid-1;
            }
        }
        
        return -1;
    }
};