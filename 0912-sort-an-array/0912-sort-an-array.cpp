class Solution {
public:
    
    void mergeTwoSortedArrays(vector<int> &nums, int low, int mid, int high) { //takes O(N)
        int i = low;
        int j = mid+1;
        int temp[high - low + 1]; //0...8 => 8-0+1 = 9
        int k = 0; //to iterate over temp[]
        
        while(i <= mid && j <= high) {
            if(nums[i] <= nums[j]) {
                temp[k] = nums[i];
                i++; 
                k++;
            } 
            else {
                temp[k] = nums[j];
                j++; 
                k++;
            }
        }
        
        while(i <= mid) {
            temp[k] = nums[i];
            i++; 
            k++;
        }
        
        while(j <= high) {
            temp[k] = nums[j];
            j++; 
            k++;
        }
        
        k = 0;
        //now temp has the sorted array, copy back to the original array
        for(int i = low; i <= high; i++) {
            nums[i] = temp[k];
            k++;
        }
    }
    
    void mergeSort(vector<int> &nums, int low, int high) { //divides array into 2 parts which takes O(logN)
        if(low >= high) {
            return;
        }
        int mid = (low + high)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        mergeTwoSortedArrays(nums, low, mid, high);
        return;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        // Merge Sort => based on divide and merge
        // TC: O(N*logN) where divide takes O(logN) and after dividing array into parts, it is merged which takes O(N)
        // SC: O(N) for using temp array
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};