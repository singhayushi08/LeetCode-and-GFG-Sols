//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
    bool f(int idx, int target, vector<int> &arr) {
        if(target == 0) return true;
        if(idx == 0) return (arr[0] == target);
        
        int notPick = f(idx-1, target, arr);
        int pick = false;
        if(arr[idx] <= target) {
            pick = f(idx-1, target-arr[idx], arr);
        }
        
        return pick | notPick;
    }
    
    bool memo(int idx, int target, vector<int> &arr, vector<vector<int>> &dp) {
        if(target == 0) return true;
        if(idx == 0) return (arr[0] == target);
        
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int notPick = memo(idx-1, target, arr, dp);
        int pick = false;
        if(arr[idx] <= target) {
            pick = memo(idx-1, target-arr[idx], arr, dp);
        }
        
        return dp[idx][target] = pick | notPick;
    }
    
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        
        // Recursion, TC: O(2^n), SC: O(n)
        // return f(n-1, sum, arr);
        
        // Memoization, TC: O(n*sum), SC: O(n*sum + n) for 2d dp and aux stack space
        // two values are changing => idx and target/sum
        // mav value of idx: 0 to n-1 and sum: 0 to sum
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return memo(n-1, sum, arr, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends