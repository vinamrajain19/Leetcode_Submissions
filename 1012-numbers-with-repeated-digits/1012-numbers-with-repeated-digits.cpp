class Solution
{
    public:
    
    
    //lz -> leading zeros-> we have leading zeroes if lz=1 else we have started with a non-zero digit
    
    int dp[1<<10][10][2][2];
    
    int f(string &s,int i,int mask,int lz,int tight)
    {
        if(i==s.length()) return 1;
        
        if(dp[mask][i][lz][tight]!=-1)
            return dp[mask][i][lz][tight];
        
        int ub = tight ? s[i]-'0': 9;
        
        int ans = 0;
        
        for(int j=0;j<=ub;j++)
        {
            if((mask&(1<<j))&&lz==0) continue; // repeated no
            
            mask|=(1<<j);                 // mask it
            
            ans+=f(s,i+1,mask,lz&(j==0),tight&(j==ub));
            
            mask^=(1<<j); // unmask it
        }
        
        return dp[mask][i][lz][tight]=ans;
    }
    
  
    int numDupDigitsAtMostN(int n)
    {
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        int mask=0;
        int ans = (n+1)-f(s,0,mask,1,1);
        return ans;
    }
};