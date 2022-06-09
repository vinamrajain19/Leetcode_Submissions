
class Solution{
public:

   
    int mod = 1003;
    int solve(string s,int i,int j,bool istrue,vector<vector<vector<int>>> &dp){
        //base case
        if(i>j) return 0;
        
        if(i == j){
            if(istrue == true ){
                return s[i] == 'T' ? 1 : 0;
            }
            else{
                return s[i] == 'F' ? 1 : 0;
            }
        }
        
        //dp
        if(dp[i][j][istrue] != -1) return dp[i][j][istrue];
        
        
        int ans = 0;
        
        for(int k = i+1;k <= j-1; k+=2){
            int lt = solve(s,i,k-1,true,dp);
            int lf = solve(s,i,k-1,false,dp);
            int rt = solve(s,k+1,j,true,dp);
            int rf = solve(s,k+1,j,false,dp);
            
            //check operator
            
            if(s[k] == '&'){
                if(istrue){
                    ans += lt*rt;
                }
                else{
                    ans += (lf*rf) + (lf*rt) + (lt*rf);
                }
            }
            else if(s[k] == '|'){
                if(istrue){
                    ans += (lt*rt) + (lf*rt) + (lt*rf);
                }else{
                    ans += (rf*lf);
                }
            }
            else if(s[k] == '^'){
                if(istrue){
                    ans += (lt*rf) + (lf*rt);
                }
                else{
                    ans += (rt*lt) + (lf*rf);
                }
            }
        }
        
        return dp[i][j][istrue] = ans % mod;
    }
    int countWays(int N, string s){
         vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        return solve(s,0,N-1,true,dp) % mod;
    }
};
