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
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<int> v;
        for(int j=0; j<col; j++) {
            v.push_back(matrix[0][j]-'0');
        }
        int maxArea = largestRectangleArea(v);
        
        for(int i=1; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(matrix[i][j] == '1') {
                    v[j] += 1;
                } else {
                    v[j] = 0;
                }
            }
            // now the curr row is updated, find largest rectangle area again
            int area = largestRectangleArea(v);
            maxArea = max(area, maxArea);
        }
        
        return maxArea;
    }
};