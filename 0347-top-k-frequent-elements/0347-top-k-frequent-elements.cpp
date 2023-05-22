class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto i: nums) {
            mp[i]++;
        }
        
        //store all freq and element as pair in max heap
        priority_queue<pair<int,int>> pq;
        for(auto i: mp) {
            pq.push(make_pair(i.second, i.first));
        }
        
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};