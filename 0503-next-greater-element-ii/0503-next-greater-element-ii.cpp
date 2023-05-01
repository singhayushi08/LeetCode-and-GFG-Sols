class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Brute force, TC: O(n^2), SC: O(1)
//         int n = nums.size();
//         vector<int> ans(n,-1);
        
//         for(int i=0; i<n; i++) {
//             int j=(i+1)%n;
//             while(j != i) {
//                 if(nums[j] > nums[i]) {
//                     ans[i] = nums[j];
//                     break;
//                 }
//                 j = (j+1)%n; // instead of j++ coz circular array
//             }
//         }
        
//         return ans;
        
        // Using Stack, TC: O(2n + 2n) for traversing the loop and sometimes while loop, SC: O(n) for storing elements in stack
        // if you just copy paste nums[]at the end of given array and then do next greater element using stack, its done
        // but we dont need to do this in extra space, just traverse the array twice
        
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n);
        
        for(int i=2*n-1; i>=0; i--) {
            int curr = nums[i%n];
            while(!s.empty() && s.top()<=curr) {
                s.pop();
            }
            if(i < n) {
                if(!s.empty()) ans[i] = s.top();
                else ans[i] = -1;
            }
            s.push(curr);
        }
        
        return ans;
        
    }
};