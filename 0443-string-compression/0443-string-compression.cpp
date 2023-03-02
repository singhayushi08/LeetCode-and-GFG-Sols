class Solution {
public:
    int compress(vector<char>& chars) {
        // TC: O(N), SC: O(N)
//         if(chars.size() == 1) return 1;
        
//         int n = chars.size();
//         int i = 0;
//         string s = "";
//         while(i < n) {
//             int count = 1; //for curr char
//             while(i < n-1 && chars[i] == chars[i+1]) {
//                 count++;
//                 i++;
//             } 
        
//             if(count == 1) {
//                 s += chars[i];        
//             } else {
//                 s += chars[i];
//                 s += to_string(count);
//             }
//             i++;
//         }
//         cout<<s<<endl;
        
//         int k = 0;
//         // copy back this s into chars
//         for(int i=0; i<s.size(); i++) {
//             chars[k] = s[i];
//             k++;
//         }
        
//         return s.size();
        
        // Using constant space, TC: O(N), SC: O(1)
        int n = chars.size();
        if(n == 1) return 1;
        
        int i = 0; // to traverse the original array
        int k = 0; // to traverse the compressed array (modified in original array)
        while(i < n) {
            int count = 1; // count of curr char
            while(i < n-1 && chars[i] == chars[i+1]) {
                i++;
                count++;
            }
            
            if(count == 1) {
                chars[k] = chars[i];
                k++; 
                i++;
            } else if(count < 10) {
                chars[k] = chars[i];
                k++;
                i++;
                chars[k] = count+'0';
                k++;
            } else {
                chars[k] = chars[i];
                k++;
                i++;
                string str = "";
                str += to_string(count);
                for(int j=0; j<str.size(); j++) {
                    chars[k] = str[j];
                    k++;
                }
            }
        }
        
        return k;
        
    }
};