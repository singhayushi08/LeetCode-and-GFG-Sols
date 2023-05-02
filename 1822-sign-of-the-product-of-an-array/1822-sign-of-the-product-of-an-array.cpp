class Solution {
public:
    int arraySign(vector<int>& nums) {
        // count no. of negative signs in nums, TC: O(n), SC: O(1)
//         int cnt_neg = 0; 
        
//         for(int i=0; i<nums.size(); i++) {
//             if(nums[i] == 0) return 0;
//             else if(nums[i] < 0) cnt_neg++;
//         }
        
//         if(cnt_neg % 2 == 0) return 1;
//         else return -1;
        
        // Keep track of sign while mutlipying, TC: O(n), SC: O(1)
        int sign = 1;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) return 0;
            else if(nums[i] < 0) {
                if(sign == -1) { // if prod till now is -ve and curr element is also -ve, then sign becomes +ve
                    sign = 1;
                } 
                else if(sign == 1) { // if prod till now is +ve and curr element is -ve, then sign is -ve
                    sign = -1;
                }
            }
        }
        
        return sign;
    }
};