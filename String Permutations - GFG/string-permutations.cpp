//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void helper(int idx, string s, vector<string> &ans) {
        if(idx == s.size()) { //base case
            ans.push_back(s); 
            return;
        }
        
        for(int i=idx; i<s.size(); i++) {
            swap(s[i], s[idx]);
            helper(idx+1, s, ans); //call rec on further string
            swap(s[i], s[idx]); //swap it back while backtracking
        }
    }
    
    void findPermutations(string str, vector<int> &freq, string s, vector<string> &ans) {
        // base case
        if(str.size() == s.size()) {
            ans.push_back(str);
            return;
        }
        
        for(int i=0; i<freq.size(); i++) {
            if(freq[i] == 0) { 
                str += s[i]; // take this character in curr string str
                freq[i] = 1; // mark present in freq array
                findPermutations(str, freq, s, ans); // call rec
                freq[i] = 0; // mark absent
                str.pop_back(); // remove added character while backtracking
            }
        }
        
    }
    
    vector<string> permutation(string S)
    {
        // using extra space
        // TC: O(n!*n + nlogn) = O(n! * n), SC: O(n) where O(n) is for using map/freq array and another O(n) is rec stack
        vector<string> ans;
        string str = ""; // current string
        int n = S.size();
        vector<int> freq(n,0);
        findPermutations(str, freq, S, ans);
        sort(ans.begin(), ans.end()); 
        return ans;
        
        // Optimised => TC: O(n! * n), SC: O(n) for rec stack space
        // vector<string> ans;
        // helper(0, S, ans);
        // sort(ans.begin(), ans.end());
        // return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends