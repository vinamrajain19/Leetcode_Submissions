class Solution {
public:
    
    int dp[10][2][2];
    int f(int i,vector<string> &digits,string &num,bool tight,bool leadingzero){
        if(i == num.size()) return 1;
        
        
        if(dp[i][tight][leadingzero] != -1) return dp[i][tight][leadingzero];
        
        int ans = 0;
        int ub = tight ? num[i] - '0' : 9;
        
        if(leadingzero){
            ans += f(i+1,digits,num,0,1);
        }
        
        for(auto it : digits){
            int x = it[0] - '0';
            if(x <= ub) ans += f(i+1,digits,num,(tight & (ub == x)),0);
        }
        
        return dp[i][tight][leadingzero] = ans;
    }
    
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
      
        string num = to_string(n);
        memset(dp,-1,sizeof(dp));
        return f(0,digits,num,1,1)-1; // remove "00"
        
    }
};