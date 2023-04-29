//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    vector<long long> nextSmaller(long long arr[], int n) {
        vector<long long> next(n);
        stack<long long> s;
        s.push(-1);
        
        for(int i=n-1; i>=0; i--) {
            long long curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            // now the stack top has next smaller element
            next[i] = s.top();
            s.push(i);
        }
        
        return next;
    }
    
    
    vector<long long> prevSmaller(long long arr[], int n) {
        vector<long long> prev(n);
        stack<long long> s;
        s.push(-1);
        
        for(int i=0; i<n; i++) {
            long long curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            // now the stack top has next smaller element
            prev[i] = s.top();
            s.push(i);
        }
        
        return prev;
    }
    
    
    
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> next;
        next = nextSmaller(arr, n);
        vector<long long> prev;
        prev = prevSmaller(arr, n); 
        
        long long ans = INT_MIN;
        for(int i=0; i<n; i++) {
            long long l = arr[i];
            if(next[i] == -1) {
                next[i] = n;
            }
            long long b = next[i] - prev[i] - 1;
            long long area = l*b;
            ans = max(area, ans);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends