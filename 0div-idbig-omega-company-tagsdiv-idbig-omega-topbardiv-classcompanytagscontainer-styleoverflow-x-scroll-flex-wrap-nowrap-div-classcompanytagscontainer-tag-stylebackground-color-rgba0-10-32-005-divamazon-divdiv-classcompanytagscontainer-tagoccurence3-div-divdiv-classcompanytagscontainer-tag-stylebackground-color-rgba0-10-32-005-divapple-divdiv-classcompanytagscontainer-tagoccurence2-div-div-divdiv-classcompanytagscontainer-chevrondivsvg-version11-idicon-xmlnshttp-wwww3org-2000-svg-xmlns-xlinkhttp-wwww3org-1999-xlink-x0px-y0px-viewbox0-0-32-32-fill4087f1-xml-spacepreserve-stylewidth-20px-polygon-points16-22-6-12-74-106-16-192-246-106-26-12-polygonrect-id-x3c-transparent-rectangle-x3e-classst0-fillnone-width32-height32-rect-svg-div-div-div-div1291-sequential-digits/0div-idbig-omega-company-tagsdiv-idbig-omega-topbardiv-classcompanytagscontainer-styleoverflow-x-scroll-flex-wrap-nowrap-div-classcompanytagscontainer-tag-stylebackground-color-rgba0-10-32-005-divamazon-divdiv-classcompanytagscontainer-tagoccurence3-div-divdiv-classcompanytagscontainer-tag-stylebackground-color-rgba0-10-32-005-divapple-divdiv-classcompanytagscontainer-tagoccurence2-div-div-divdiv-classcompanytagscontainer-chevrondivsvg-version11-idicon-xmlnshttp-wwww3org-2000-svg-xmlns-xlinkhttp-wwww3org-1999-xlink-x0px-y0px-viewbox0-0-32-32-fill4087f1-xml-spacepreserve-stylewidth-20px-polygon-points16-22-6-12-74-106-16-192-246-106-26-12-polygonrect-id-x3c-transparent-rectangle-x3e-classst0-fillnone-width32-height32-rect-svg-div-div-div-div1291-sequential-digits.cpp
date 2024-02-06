class Solution {
    bool check(int num) {
        int ld = -1;
        while(num > 0) {
            int rem = num % 10;
            if(ld != -1 && rem != ld-1) return false;
            ld = rem;
            num = num/10;
        }
        
        return true;
    }
    
public:
    vector<int> sequentialDigits(int low, int high) {
        // brute force
//         vector<int> ans;
//         for(int i=low; i<=high; i++) {
//             if(check(i) == true) {
//                 ans.push_back(i);
//             }
//         }
        
//         return ans;
        
        // better approach, create all sequential digits starting from 1-9 & check if they are in range
//         string str1 = to_string(low); 
//         int len1 = str1.size();
//         string str2 = to_string(high);
//         int len2 = str2.size();
//         vector<int> ans;
        
//         for(int digits=len1; digits<=len2; digits++) {
//              for(int start=1; start<9; start++) { //fix the first digit and check if sequential no. can be created
//                  if(start + digits > 10) break; //if 4 digits number has to be made and starting digit is 7, 7+4>10 cannot be made
                 
//                  int num = start;
//                  int prev = start;
//                  for(int i=0; i<digits-1; i++) {
//                      num = num*10;
//                      prev += 1; 
//                      num += prev;
//                  }
                 
//                  if(num >= low && num <= high) ans.push_back(num);
//              }
//         }
        
//         return ans;
        
        // Using queue
        queue<int> q;
        for(int i=1; i<9; i++) {
            q.push(i);
        }
        vector<int> ans;
        
        while(!q.empty()){
            int num = q.front();
            cout<<num<<" ";
            if(num >= low && num <= high) ans.push_back(num);
            if(num > high) break;
            q.pop();
            
            int rem = num%10;
            if(rem < 9) {
                num = num*10;
                num += (rem+1);
            
                q.push(num);
            }
        }
        
        return ans;
    }
};