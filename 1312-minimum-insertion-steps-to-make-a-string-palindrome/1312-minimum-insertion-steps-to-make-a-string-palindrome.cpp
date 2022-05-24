class Solution {
public:
    int minInsertions(string s) {
         string s2 = string(s.rbegin(),s.rend());
        
        int m = s.size();
        int n = s2.size();
        
        vector<int> prev(n+1,0),curr(n+1,0);
        
        prev[0] = 0; 
        
        for(int j = 0;j<=n;j++){
            prev[j] = 0;
        }
        
        //main code
        for(int i = 1;i<m+1;i++){
            for(int j= 1;j<n+1;j++){
                if(s[i-1] == s2[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(prev[j],curr[j-1]);
                }
            }
            prev = curr;
        }
        return s.size() - prev[n];
    }
};