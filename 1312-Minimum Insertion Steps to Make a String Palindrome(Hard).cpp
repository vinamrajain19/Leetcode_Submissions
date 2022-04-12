class Solution {
public:
    int minInsertions(string s) {
        string r = string(s.rbegin(),s.rend());
        
        int m = s.size();
        int n = r.size();
        
        int t[m+1][n+1];
        
        //initialisation 
        for(int i = 0;i<m+1;i++){
            t[i][0] = 0;
        }
        for(int i = 0;i<n+1;i++){
            t[0][i] = 0;
        }
        
        for(int i = 1;i<m+1;i++){
            for(int j = 1;j<n+1;j++){
                if(s[i-1] == r[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return s.size() - t[m][n];
    }
};
