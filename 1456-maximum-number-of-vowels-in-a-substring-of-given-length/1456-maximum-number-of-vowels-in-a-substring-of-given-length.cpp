class Solution {
public:
    
    bool is(char c){
        if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') return true;
        return false;
    }
    
    int maxVowels(string s, int k) {
        int ans = 0;
        int i = 0;
        int j = 0;
        
        int cnt = 0;
        
        while(j < s.size()){
            if(is(s[j])){
                cnt++;
            }
            
            if(j-i+1 == k){
                ans = max(ans,cnt);
                if(is(s[i])){
                    cnt--;
                }
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};