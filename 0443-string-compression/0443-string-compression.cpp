class Solution {
public:
    int compress(vector<char>& chars) {
        // TC: O(N), SC: O(N)
        if(chars.size() == 1) return 1;
        
        int n = chars.size();
        int i = 0;
        string s = "";
        while(i < n) {
            int count = 1; //for curr char
            while(i < n-1 && chars[i] == chars[i+1]) {
                count++;
                i++;
            } 
        
            if(count == 1) {
                s += chars[i];        
            } else {
                s += chars[i];
                s += to_string(count);
            }
            i++;
        }
        cout<<s<<endl;
        
        int k = 0;
        // copy back this s into chars
        for(int i=0; i<s.size(); i++) {
            chars[k] = s[i];
            k++;
        }
        
        return s.size();
    }
};