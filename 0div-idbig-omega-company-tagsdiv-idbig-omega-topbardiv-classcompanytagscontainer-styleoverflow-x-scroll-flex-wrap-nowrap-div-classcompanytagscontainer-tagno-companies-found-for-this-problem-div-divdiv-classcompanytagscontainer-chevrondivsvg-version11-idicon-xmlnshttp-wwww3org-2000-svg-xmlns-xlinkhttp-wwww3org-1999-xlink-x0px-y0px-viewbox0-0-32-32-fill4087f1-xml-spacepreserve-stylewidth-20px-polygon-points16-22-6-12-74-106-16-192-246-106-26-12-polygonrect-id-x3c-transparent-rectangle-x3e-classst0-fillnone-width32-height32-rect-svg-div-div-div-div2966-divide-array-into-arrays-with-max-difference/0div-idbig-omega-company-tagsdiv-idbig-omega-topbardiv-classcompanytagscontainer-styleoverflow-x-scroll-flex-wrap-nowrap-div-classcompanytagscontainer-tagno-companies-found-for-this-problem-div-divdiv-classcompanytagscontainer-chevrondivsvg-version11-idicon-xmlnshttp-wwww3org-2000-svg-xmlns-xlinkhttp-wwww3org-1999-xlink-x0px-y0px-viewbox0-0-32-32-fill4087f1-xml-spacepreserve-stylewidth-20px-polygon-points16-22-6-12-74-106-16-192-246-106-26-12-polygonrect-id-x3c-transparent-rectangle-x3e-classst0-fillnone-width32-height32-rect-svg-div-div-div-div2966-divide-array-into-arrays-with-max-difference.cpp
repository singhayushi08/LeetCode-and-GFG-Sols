class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        // TC: O(nlogn), SC: O(3)
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        bool condn = true;
        vector<int> v;
        v.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); i++) {
            if(v.size() == 3) {
                ans.push_back(v);
                vector<int> temp;
                v = temp;
                v.push_back(nums[i]);
            }
            else if(nums[i] - v[0] <= k && v.size() < 3) { //logic is simple, if curr element - min element of array <= k then its fine
                v.push_back(nums[i]);
            }
            else if(nums[i] - v[0] > k && v.size() < 3) { //otherwise there is no point going forward coz the array is sorted so the elements in between min and curr element will always satisfy the condition but all elements diff in array should be <= k
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