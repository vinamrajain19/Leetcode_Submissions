class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        
        while(a or b or c){
            int last_a = a & 1;
            int last_b = b & 1;
            int last_c = c & 1;
            
            if(last_c == 1 and last_b == 0 and last_a == 0) ans++;
            else if(last_c == 0 and last_a == 1 and last_b == 1) ans+=2;
            else if(last_c == 0 and last_a == 1 and last_b == 0) ans++;
            else if(last_c == 0 and last_a == 0 and last_b == 1) ans++;
            
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return ans;
    }
};