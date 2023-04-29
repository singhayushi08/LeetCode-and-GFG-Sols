class Solution {
    vector<int> nextSmaller(vector<int> &arr, int n) { // takes O(N) tc and sc
        vector<int> next(n);
        stack<int> s;
        s.push(-1);
        
        for(int i=n-1; i>=0; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            // now stack top is the next smaller element index
            next[i] = s.top();
            s.push(i);
        }
        
        return next;
    }
    
    vector<int> prevSmaller(vector<int> &arr, int n) { // takes O(N) tc and sc
        vector<int> prev(n);
        stack<int> s;
        s.push(-1);
        
        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            // now stack top is the next smaller element index
            prev[i] = s.top();
            s.push(i);
        }
        
        return prev;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        // Using stacks, TC: O(N), SC: O(N)
        int n = heights.size();
        vector<int> next;
        next = nextSmaller(heights, n);
        vector<int> prev;
        prev = prevSmaller(heights, n);
        
        int maxArea = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            if(next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int currArea = l*b;
            maxArea = max(currArea, maxArea);
        }
        
        return maxArea;
    }
};