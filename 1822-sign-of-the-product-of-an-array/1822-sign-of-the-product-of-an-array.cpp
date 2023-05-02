class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt_neg = 0; // count no. of negative signs in nums
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) return 0;
            else if(nums[i] < 0) cnt_neg++;
        }
        
        if(cnt_neg % 2 == 0) return 1;
        else return -1;
    }
};