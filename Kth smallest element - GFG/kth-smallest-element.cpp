//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        // Sorting, TC: O(nlogn), SC: O(1)
        // int n = r-l+1;
        // sort(arr, arr+n);
        // return arr[k-1];
        
        // Using set, TC: O(nlogn), SC: O(logn)
        // set<int> s;
        // for(int i=l; i<=r; i++) {
        //     s.insert(arr[i]);
        // }
        
        // int cnt=0;
        // for(auto i: s) {
        //     cnt++;
        //     if(cnt == k) return i;
        // }
        
        //Using min heap, TC: O(klogk + n-klogk)
        priority_queue<int> pq;
        for(int i=l; i<k; i++) {
            pq.push(arr[i]);
        }
        
        for(int i=k; i<=r; i++) {
            int mini = pq.top();
            if(arr[i] < mini) {
                pq.push(arr[i]);
                pq.pop();
            }
        }
        
        return pq.top();
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends