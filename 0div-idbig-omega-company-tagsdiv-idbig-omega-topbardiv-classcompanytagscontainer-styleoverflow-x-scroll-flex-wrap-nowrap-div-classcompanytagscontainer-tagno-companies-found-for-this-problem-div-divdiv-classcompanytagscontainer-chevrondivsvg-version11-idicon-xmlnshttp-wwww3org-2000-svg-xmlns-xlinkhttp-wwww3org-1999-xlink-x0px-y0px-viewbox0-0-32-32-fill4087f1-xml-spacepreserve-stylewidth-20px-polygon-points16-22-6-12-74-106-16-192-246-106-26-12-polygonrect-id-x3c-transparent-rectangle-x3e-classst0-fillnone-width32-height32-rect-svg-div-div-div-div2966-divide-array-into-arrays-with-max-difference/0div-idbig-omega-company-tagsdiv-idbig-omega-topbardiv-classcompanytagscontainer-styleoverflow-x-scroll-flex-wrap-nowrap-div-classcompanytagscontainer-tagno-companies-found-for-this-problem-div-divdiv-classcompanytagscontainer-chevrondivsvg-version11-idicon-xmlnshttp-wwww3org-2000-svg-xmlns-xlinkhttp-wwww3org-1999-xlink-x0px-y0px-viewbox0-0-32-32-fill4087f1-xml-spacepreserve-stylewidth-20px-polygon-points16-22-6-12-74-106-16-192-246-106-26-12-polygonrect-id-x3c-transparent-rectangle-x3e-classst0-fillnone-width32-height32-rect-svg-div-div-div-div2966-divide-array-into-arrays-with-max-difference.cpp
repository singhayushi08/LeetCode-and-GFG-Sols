class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(auto i: nums) cout<<i<<" ";
        cout<<endl;
        bool condn = true;
        vector<int> v;
        v.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); i++) {
            if(v.size() == 3) {
                ans.push_back(v);
                vector<int> temp;
                v = temp;
                v.push_back(nums[i]);
                // for(auto i: v) cout<<i<<" ";
            }
            else if(nums[i] - v[0] <= k && v.size() < 3) {
                v.push_back(nums[i]);
            }
            else if(nums[i] - v[0] > k && v.size() < 3) {
                condn = false;
                break;
            }
            
        }
        
        if(condn == false) {
            vector<vector<int>> empty_ans;
            return empty_ans;
        }
        
        if(v.size() == 3) ans.push_back(v);
        return ans;
    }
};