class Solution {
public:
    
    int mod = 1e9+7;
    
    int numSub(string s) {
        int i = 0;
        int j = 0;
        int ans = 0;
        int c = 0;
        
        while(j < s.size()){
            
            if(s[j] == '0')  c++;
            
            while(i <= j and c > 0){
                if(s[i] == '0') c--;
                i++;
            }
            
            ans = (ans + j-i+1) % mod;
            j++;
        }
        
        return ans % mod;
    }
};