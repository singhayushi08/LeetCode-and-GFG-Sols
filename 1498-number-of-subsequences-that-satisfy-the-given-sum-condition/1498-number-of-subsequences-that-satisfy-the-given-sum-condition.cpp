class Solution {
    int mod = 1e9 + 7;
    
    int f(int idx, vector<int>& nums, int target, vector<int>& v) {
        if(idx == nums.size()) { // base case
            if(v.size() != 0) {
                int sum = v[0] + v[v.size()-1];
                if(sum <= target) {
                    return 1;
                } else {
                    return 0;
                }
            }
            return 0;
        }
        
        v.push_back(nums[idx]);
        int pick = f(idx+1, nums, target, v)%mod;
        v.pop_back();
        int notPick = f(idx+1, nums, target, v)%mod;
        
        return (pick + notPick)%mod;
    }
    
    long helper(int x, int y) { // gives x^y
        if(y == 0) return 1;
        if(x == 0) return 0;
        long ans = 1;
        if(y % 2 == 0) {
            ans = helper(x, y/2);
            ans *= ans;
        }
        if(y % 2 != 0) {
            ans = helper(x, y-1);
            ans *= x;
        }
        
        return ans%mod;
    }
    
public:
    int numSubseq(vector<int>& nums, int target) {
        // Brute Force- find all subsequences using recursion, TC: O(2^n), SC: O(n)
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // vector<int> v;
        // return f(0, nums, target, v);
        
        // Optimal
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        
        // now apply two pinter just like two sum 
        int i=0, j=n-1;
        while(i <= j) {
            if(nums[i] + nums[j] <= target) {
                ans += helper(2,j-i);
                ans = ans%mod;
                i++;
            }
            else {
                j--;
            }
        }
        
        return ans%mod;
        
    }
};