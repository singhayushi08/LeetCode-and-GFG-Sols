class Solution {
public:
    int numberOfChild(int n, int k) {
//         if(k < n) return k;
//         int sec = n; //you are at n-1th pos, seconds passed = n
//         int reset=n-2;
        
//         for(int i=reset; i>=0; i--) {
//             cout<<"pos: "<<i<<" sec: "<<sec<<endl;
//             if(k == sec) return i;
//             if(i == 0) {
//                 if(k-sec >= 0 && (k-sec)<=(n-1)) {
//                     cout<<"got the ans: "<<endl;
//                     return i + (k-sec);
//                 } else if ((k-sec) > (n-1)) {
//                     sec += n-1;
//                     i = reset = n-1;
//                     sec++;
//                     cout<<"come here, sec: "<<sec<<" pos: "<<reset<<endl;
//                     continue;
//                 }
//             }
//             cout<<"am i here?"<<endl;
//             sec++;
//         }
        
//         return -1;
        
        // 1 second = 1 pass, so k seconds = k passes should be done, whichever index has the ball after these k passes, that is the answer
        // 1 iteration = 0 to n-1 (left to right), 1 iteration has n-1 passes. Ex: 5 children -> 4 passes
        // find total no of iterations that can be fully made = k/(n-1)
        // Ex: 1. k = 20, n = 5 -> total iterations = 20/4 = 5 2. k = 22, n = 5 -> total iterations = 4.4
        
        if((k/(n-1)) % 2 == 0) { //that means we are 0th index, which ever passes are left that is the index
            return k%(n-1);
        } else {
            return (n-1)-(k%(n-1));
        }
    }
};