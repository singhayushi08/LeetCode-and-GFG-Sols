class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        //  linear search, TC: O(N), SC: O(1)
        // for(auto ch: letters) {
        //     if(ch > target) {
        //         return ch;
        //     }
        // }
        // return letters[0];
        
        // Binary search, TC: O(log N), SC: O(1)
        int n = letters.size();
        if(target >= letters[n-1]) return letters[0];
        int s = 0, e = n-1;
        char ans;
        while(s <= e) {
            int mid = (s+e)/2;
            if(letters[mid] > target) {
                ans = letters[mid];
                e = mid - 1; // go left
            }
            else { // go right
                s = mid + 1;
            }
        }
        return ans;
    }
    
};