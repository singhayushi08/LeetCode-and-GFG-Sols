//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // TC: O(n^2), SC: O(3n)
	    // {1, 2, 5} is LIS, {3, 2} is also LIS if seen from backwards
	    int n = nums.size();
	    if(n == 1) return 1;
	    
	    vector<int> dp1(n, 1), dp2(n, 1);
	    for(int i=1; i<n; i++) { // longest increasing subsequence
	        for(int prev=0; prev<i; prev++) {
	            if(nums[prev] < nums[i] && dp1[i] < 1 + dp1[prev]) {
	                dp1[i] = 1 + dp1[prev];
	            }
	        }
	    }
	    
	    for(int i=n-2; i>=0; i--) { // reverse longest increasing subsequence
	        for(int prev=n-1; prev>i; prev--) {
	            if(nums[prev] < nums[i] && dp2[i] < 1 + dp2[prev]) {
	                dp2[i] = 1 + dp2[prev];
	            }
	        }
	    }
	    
	    vector<int> bitonic(n,0);
	    int maxi = 1;
	    for(int i=0; i<n; i++) {
	        bitonic[i] = dp1[i] + dp2[i] - 1; // removing common
	        maxi = max(maxi, bitonic[i]);
	    }
	    
	    return maxi;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends