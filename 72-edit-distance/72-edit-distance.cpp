class Solution {
public:
 /*   int help(string &s1, string &s2,int i,int j,vector<vector<int>> &dp) {
       
        if(j<0) return i+1;
        if(i<0) return j+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i] == s2[j]) return dp[i][j] = help(s1,s2,i-1,j-1,dp);
        
        //insert -> f(i,j-1)   delete -> f(i-1,j)     replace -> f(i-1,j-1)
        
        return dp[i][j] = 1 + min(help(s1,s2,i-1,j-1,dp) ,min(help(s1,s2,i-1,j,dp) , help(s1,s2,i,j-1,dp)));
    } */
    
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
      //  vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        vector<int> prev(m+1,0),temp(m+1,0);
    
        
        for(int j = 0;j<m+1;j++){
            prev[j] = j;
        }
        
        for(int i = 1;i<n+1;i++){
            
            temp[0] = i;
            
            for(int j = 1;j<m+1;j++){
                if(s1[i-1] == s2[j-1]) temp[j] = prev[j-1];
                else{
                    temp[j] = 1 + min({prev[j-1] , prev[j] ,temp[j-1]});
                }
            }
            prev = temp;
        }
        
        return prev[m];
    }
};