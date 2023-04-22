class Solution {
public:
    
    
    int minInsertions(string s) {
        string s2 = string(s.rbegin(),s.rend());
        
        int m = s.size();
        int n = s2.size();
        
        vector<int> prev(n+1,0),curr(n+1,0);
        
        prev[0] = 0; 
       
        for(int i = n-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(s[i] == s2[j]){
                    curr[j] = 1 + prev[j+1];
                }
                else{
                    curr[j] = max(prev[j],curr[j+1]);
                }
            }
            prev = curr;
        }
        return s.size() - prev[0];
    }
};