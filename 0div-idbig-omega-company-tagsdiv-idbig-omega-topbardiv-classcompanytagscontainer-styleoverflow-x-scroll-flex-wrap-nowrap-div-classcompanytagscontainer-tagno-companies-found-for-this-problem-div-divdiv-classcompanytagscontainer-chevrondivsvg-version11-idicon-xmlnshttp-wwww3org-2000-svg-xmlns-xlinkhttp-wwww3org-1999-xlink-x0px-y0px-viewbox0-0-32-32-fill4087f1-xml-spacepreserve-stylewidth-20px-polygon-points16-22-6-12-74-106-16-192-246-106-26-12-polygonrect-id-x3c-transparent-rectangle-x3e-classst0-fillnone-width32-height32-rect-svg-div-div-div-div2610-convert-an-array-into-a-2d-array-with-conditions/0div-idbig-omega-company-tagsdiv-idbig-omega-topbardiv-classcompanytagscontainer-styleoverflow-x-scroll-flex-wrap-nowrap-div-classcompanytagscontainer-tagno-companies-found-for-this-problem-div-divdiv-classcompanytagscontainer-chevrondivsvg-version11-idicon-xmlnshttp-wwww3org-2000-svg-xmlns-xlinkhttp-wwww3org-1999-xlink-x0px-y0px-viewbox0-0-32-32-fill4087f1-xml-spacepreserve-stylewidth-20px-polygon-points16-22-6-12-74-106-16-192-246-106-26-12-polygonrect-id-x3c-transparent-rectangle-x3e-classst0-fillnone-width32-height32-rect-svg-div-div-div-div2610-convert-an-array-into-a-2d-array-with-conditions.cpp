class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // 1:3,2
        //     3:2,1
        //         4:1,0
        //             2:1,0
        //                 1,3,4,2
        //                 1,3
        //                 1
        vector<vector<int>> ans;
        unordered_map<int,int> mp; // to store element and its freq
        int max_freq = 0;
        for(auto i: nums) {
            mp[i] += 1;
            max_freq = max(max_freq,mp[i]);
        }
        // for(auto i: mp) {
        //     cout<<i.first<<" : "<<i.second<<endl;
        // }
        for(int i=0; i<max_freq; i++) {
            vector<int> temp;
            for(auto& i: mp) {
                if(i.second>0) {
                    temp.push_back(i.first);
                    i.second--;
                }
            }
            ans.push_back(temp);
            
        }
    
        return ans;
    }
};