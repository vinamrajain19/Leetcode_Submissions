class Solution {
public:
    int dp[366][396];
    int f(vector<int> &days,vector<int> &costs,int idx,int valid){
        if(idx == days.size()) return 0;
        
        if(dp[idx][valid] != -1) return dp[idx][valid];
        
        if(valid < days[idx]){
            return dp[idx][valid] =  min({costs[0] + f(days,costs,idx+1,days[idx]),costs[1] + f(days,costs,idx+1,days[idx] + 6),costs[2]+f(days,costs,idx+1,days[idx] + 29)});
        }
        
        return dp[idx][valid] = f(days,costs,idx+1,valid);
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return f(days,costs,0,0);
    }
};