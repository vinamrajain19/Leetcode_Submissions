class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
       // vector<vector<int>> dp(t.size(),vector<int>(t.size(),-1));
        
        int n = t.size();
        
        vector<int> last(n,0);
        
        for(int j = 0;j<n;j++){
            last[j] = t[n-1][j];
        }
        
        for(int i = n-2;i>=0;i--){
            vector<int> temp(n,0);
            for(int j = i;j>=0;j--){
                int d = t[i][j] + last[j];
                int dia = t[i][j] + last[j+1];
                
                temp[j] = min(d,dia);
            }
            last = temp;
        }
        
        return last[0];
        
    }
    
};