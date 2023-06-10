class Solution {
public:
    
    int mod = 1e9+7;
    int dp[24][3][405];
    
    int f(string n1,int i,int tight,int sum,int &min_sum,int &max_sum){
        
        if(i == n1.size()){
            if(sum >= min_sum and sum <= max_sum) return 1;
            return 0;
        }
        
        if(dp[i][tight][sum] != -1) return dp[i][tight][sum];
        
        int lb = tight ? n1[i] -'0' : 9;
        
        int ans = 0;
        
        for(int dig = 0;dig <= lb;dig++){
            ans  = (ans + f(n1,i+1,(tight & (dig == lb)),sum+dig,min_sum,max_sum)) % mod;
           
        }
        
        return dp[i][tight][sum] = ans%mod;
    }
    
    int count(string num1, string num2, int min_sum, int max_sum) {
        
        
        memset(dp,-1,sizeof(dp));
        int ans1 = f(num1,0,1,0,min_sum,max_sum);
        
        int sum=0;
        
        for(int i=0;i<num1.size();i++) sum += num1[i] - '0';
        
        if(sum>=min_sum && sum<=max_sum)
        {
            ans1--;
        }
        
        memset(dp,-1,sizeof(dp));
        int ans2 = f(num2,0,1,0,min_sum,max_sum);
        
        return (ans2-ans1+mod) % mod;
    }
};