class Solution {
public:
    double average(vector<int>& salary) {
        // Sort the array, TC: O(nlogn), SC: O(1)
//         sort(salary.begin(), salary.end());
//         int n = salary.size();
//         if(n == 3) return double(salary[1]);
        
//         double ans = 0.0;
//         for(int i=1; i<n-1; i++) {
//             ans += salary[i];
//         }
//         return ans/(n-2);
        
        // Optimal, TC: O(n), SC: O(1)
        int n = salary.size();
        int maxi = INT_MIN, mini = INT_MAX;
        int sum = 0;
        
        for(int i=0; i<salary.size(); i++) {
            sum += salary[i];
            maxi = max(salary[i], maxi);
            mini = min(salary[i], mini);
        }
        
        sum = sum-maxi-mini;
        return double(sum)/(n-2);
    }
};