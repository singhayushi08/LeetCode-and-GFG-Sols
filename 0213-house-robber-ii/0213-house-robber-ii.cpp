class Solution {
    int f(int idx, vector<int> &nums) { //space optimization solution of house robber 1
        int prev2 = 0;
        int prev1 = nums[0];
        
        for(int i=1; i<nums.size(); i++) {
            int pick = nums[i];
            if(i >= 2) pick += prev2;
            int notPick = 0 + prev1;
            
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; //no adjacents if only 1 element
        
        // since you cannot have both the 0th and (n-1)th elements in the ans
        // we calculate two answers: by removing 0th from nums and removing n-1th from nums
        // max of both will be the final ans
        vector<int> temp1, temp2;
        
        for(int i=0; i<n; i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }
        
        return max(f(n-1, temp1), f(n-1, temp2));
    }
};