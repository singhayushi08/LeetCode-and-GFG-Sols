class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Sorting, TC: O(nlogn), SC: O(1)
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()-k];
        
        // Using min priority queue, TC: O(nlogk), SC: O(k)
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<k; i++) { // push first k elements in min heap
            pq.push(nums[i]);
        }
        
        for(int i=k; i<nums.size(); i++) {
            int curr = nums[i];
            if(curr > pq.top()) { //pq.top() gives min element in heap
                pq.push(curr);
                pq.pop();
            }
        }
        
        return pq.top();
        
        
        
    }
};