class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n = str2.size();
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        //main code
        for(int i = 1;i<m+1;i++){
            for(int j= 1;j<n+1;j++){
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }

        }
        
        int lcs = dp[m][n];
        
        int i = m;
        int j = n;
        
        string ans = "";
        
        while(i > 0  and j > 0){
            if(str1[i-1] == str2[j-1]){
                ans =  str1[i-1] + ans;
                i--;
                j--;
            }
            else{
                
                if(dp[i-1][j] > dp[i][j-1]){
                    ans = str1[i-1] + ans;
                    i--;
                }
                else{
                    ans = str2[j-1] + ans;
                    j--;
                }
                
            
            }
            
        }
        
        while(i > 0){
            ans = str1[i-1] + ans;
            i--;
        }
        
        while(j > 0){
            ans = str2[j-1] + ans;
            j--;
        }
        
        return ans;
        
        
    }
};