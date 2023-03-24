//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int mod = 1e9 + 7;
    
    int countSubsetsWithSumK(vector<int> &arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(k+1, 0));
    
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
    
        if(arr[0] <= k && arr[0] != 0) dp[0][arr[0]] = 1;
    
        for(int i=1; i<n; i++) {
            for(int target=0; target<=k; target++) {
                int notPick = dp[i-1][target];
                int pick = 0;
                if(arr[i] <= target)
                    pick = dp[i-1][target-arr[i]];
    
                dp[i][target] = (pick + notPick)%mod;
            }
        }
    
        return dp[n-1][k];
    }
    
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum = 0;
        for(int i=0; i<n; i++) totalSum += arr[i];
        if(totalSum - d < 0 || (totalSum - d) % 2 != 0) return 0;
        return countSubsetsWithSumK(arr, (totalSum - d) / 2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends