class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;
        int ans = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        
        while(j < s.size()){
            if(s[j] == 'a') a++;
            else if(s[j] == 'b') b++;
            else if(s[j] == 'c') c++;
            
            while(a >= 1 and b >= 1 and c >= 1){
                ans += (s.size()-j);
                
                if(s[i] == 'a') a--;
                else if(s[i] == 'b') b--;
                else if(s[i] == 'c') c--;
                
                i++;
            }
            
            j++;
        }
        
        return ans;
    }
};