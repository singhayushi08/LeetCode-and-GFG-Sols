class Solution {
    vector<int> nextGreater(vector<int>& nums2, int n) {
        vector<int> next(n);
        stack<int> s;
        s.push(-1);
        
        for(int i=n-1; i>=0; i--) {
            int curr = nums2[i];
            while(s.top() != -1 && s.top() <= curr) {
                s.pop();
            }        
            if(s.empty()) next[i] = -1;
            else next[i] = s.top();
            s.push(curr);
        }
        
        return next;
    }
    
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> next;
        next = nextGreater(nums2, nums2.size());
        
        map<int,int> mp; // key is elements of nums2 and its next greater element is the value
        for(int i=0; i<nums2.size(); i++) {
            mp[nums2[i]] = next[i];
        }
        
        vector<int> ans(nums1.size());
        for(int i=0; i<nums1.size(); i++) {
            ans[i] = mp[nums1[i]];
        }
        
        return ans;
    }
};