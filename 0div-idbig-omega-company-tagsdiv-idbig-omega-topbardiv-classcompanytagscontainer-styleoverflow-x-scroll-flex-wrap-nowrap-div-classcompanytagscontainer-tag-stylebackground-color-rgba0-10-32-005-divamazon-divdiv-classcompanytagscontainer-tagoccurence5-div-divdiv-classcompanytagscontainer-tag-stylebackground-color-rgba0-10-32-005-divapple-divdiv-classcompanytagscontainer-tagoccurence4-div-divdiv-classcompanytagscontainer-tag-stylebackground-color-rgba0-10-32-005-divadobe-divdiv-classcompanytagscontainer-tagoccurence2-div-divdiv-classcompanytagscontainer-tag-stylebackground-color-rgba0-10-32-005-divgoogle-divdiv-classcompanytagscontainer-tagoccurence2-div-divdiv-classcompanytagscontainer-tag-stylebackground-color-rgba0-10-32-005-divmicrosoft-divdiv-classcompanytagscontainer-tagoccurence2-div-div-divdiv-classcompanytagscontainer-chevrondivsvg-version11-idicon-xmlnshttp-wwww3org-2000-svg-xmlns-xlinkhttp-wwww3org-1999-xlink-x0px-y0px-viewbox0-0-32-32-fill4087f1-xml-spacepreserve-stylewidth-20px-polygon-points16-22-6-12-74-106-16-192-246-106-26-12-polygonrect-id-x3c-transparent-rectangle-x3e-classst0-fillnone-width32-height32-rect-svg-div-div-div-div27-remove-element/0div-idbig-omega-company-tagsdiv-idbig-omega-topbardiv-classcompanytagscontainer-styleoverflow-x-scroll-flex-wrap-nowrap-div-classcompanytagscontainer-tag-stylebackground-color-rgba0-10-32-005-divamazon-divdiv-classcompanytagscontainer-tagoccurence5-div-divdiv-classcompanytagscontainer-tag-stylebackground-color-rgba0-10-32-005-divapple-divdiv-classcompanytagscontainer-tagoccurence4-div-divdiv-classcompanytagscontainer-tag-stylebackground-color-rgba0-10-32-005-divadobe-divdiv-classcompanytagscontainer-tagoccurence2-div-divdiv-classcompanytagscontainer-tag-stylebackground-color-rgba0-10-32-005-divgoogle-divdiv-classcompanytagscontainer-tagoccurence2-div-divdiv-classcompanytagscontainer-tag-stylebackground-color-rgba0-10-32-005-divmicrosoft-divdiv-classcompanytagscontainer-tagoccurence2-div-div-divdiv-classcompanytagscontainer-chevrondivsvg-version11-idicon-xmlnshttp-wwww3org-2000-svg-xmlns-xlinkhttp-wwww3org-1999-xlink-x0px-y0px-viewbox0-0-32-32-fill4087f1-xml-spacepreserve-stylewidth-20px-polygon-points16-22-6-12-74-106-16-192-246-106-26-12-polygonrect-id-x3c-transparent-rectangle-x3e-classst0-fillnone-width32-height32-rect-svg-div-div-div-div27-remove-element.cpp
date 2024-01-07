class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1 && nums[0] == val) return 0; 
        int i=0, j=nums.size()-1;
        while(i < j) {
            if(nums[i] == val && nums[j] != val) {
                // swap
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++; j--;
            }
            else if(nums[j] == val) {
                j--;
            }
            else if(nums[i] != val) {
                i++;
            }
        }
        
        int ans=0;
        for(auto i: nums){
            if(i != val) ans++;
            else break;
        }
        return ans;
    }
};