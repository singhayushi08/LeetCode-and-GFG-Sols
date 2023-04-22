class Solution {
    static bool comp(vector<int> &v1, vector<int> &v2) {
        if(v1[0] > v2[0]) return true;
        if(v1[0] < v2[0]) return false;
        // if they are same
        if(v1[1] < v2[1]) return true;
        else return false;
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(),properties.end(),comp);
        int maxTillNow = INT_MIN;
        int ans=0;
        for(auto p:properties){
            if(maxTillNow>p[1]) ans++;
            else maxTillNow=p[1];
        }
        return ans;
        
    }
};