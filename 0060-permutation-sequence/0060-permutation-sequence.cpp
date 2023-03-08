class Solution {
    void findPermutations(int idx, vector<int> &arr, int n, vector<vector<int>> &v) {
        // base case
        if(idx == n) {
            v.push_back(arr);
            return;
        }

        for(int i=idx; i<n; i++) {
            swap(arr[idx], arr[i]);
            findPermutations(idx + 1, arr, n, v);
            swap(arr[idx], arr[i]);
        }
    }
    
    void remove(vector<int> &v, int pos) {
        if(pos == v.size()-1) {
            v.pop_back();
        } else {
            for(int i=pos+1; i<v.size(); i++) {
                v[i-1] = v[i];
            }
            v.pop_back();
        }
        return;
    }

public:
    string getPermutation(int n, int k) {
        // Brute Force => save all possible permutations in a 2d vector, traverse and find kth permutation from there
        // there will be no duplicate permutation formed coz we are given 1 to n (all no. are unique)
        // TC: O(n*n! + mlogm where m is n!), SC: O(n! for 2d v vector + n for arr + n for rec stack) ~ O(n!)
        // string s ="";
        // vector<int> arr(n,0);
        // for(int i=0; i<n; i++) {
        //     arr[i] = i+1;
        // }
        // // for(auto i: arr) {
        // //     cout<<i<<" ";
        // // }
        // vector<vector<int>> v;
        // findPermutations(0, arr, n, v); //stores all possible permutations in v
        // sort(v.begin(), v.end()); //sort to get the desired sequence given in question
        // // for(auto i: v) {
        // //     for(auto j: i) {
        // //         cout<<j<<" ";
        // //     }
        // //     cout<<endl;
        // // }
        // for(auto i: v) {
        //     k--;
        //     if(k == 0) {
        //         for(auto j: i) {
        //             s += to_string(j);
        //         }
        //         cout<<s<<endl;
        //         break;
        //     }
        // }
        // return s; 
        
        // Optimal, TC: O(N^2), SC: O(N)
        string ans = "";
        vector<int> v; 
        int fact = 1;
        for(int i=1; i<=n-1; i++) {
            fact = fact * i; //calculate fact of n-1 
            v.push_back(i); 
        }
        v.push_back(n); 
        k = k-1; //acc to 0 based indexing
        while(true) {
            ans += to_string(v[k / fact]);
            remove(v, k/fact); //remove this pos element from the vector v
            if(v.size() == 0) {
                break;
            }
            k = k % fact;
            fact = fact / v.size();
        }
        return ans;
        
    }
};