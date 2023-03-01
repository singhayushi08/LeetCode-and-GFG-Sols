class Solution {
public:
    
    void mergeTwoSortedArrays(vector<int> &nums, int low, int mid, int high) {
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
    
    void mergeSort(vector<int> &nums, int low, int high) {
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
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};