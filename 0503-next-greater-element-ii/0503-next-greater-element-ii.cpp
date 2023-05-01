class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Brute force
        int n = nums.size();
        vector<int> ans(n,-1);
        
        for(int i=0; i<n; i++) {
            int j=(i+1)%n;
            while(j != i) {
                if(nums[j] > nums[i]) {
                    ans[i] = nums[j];
                    break;
                }
                j = (j+1)%n; // instead of j++ coz circular array
            }
        }
        
        return ans;
    }
};