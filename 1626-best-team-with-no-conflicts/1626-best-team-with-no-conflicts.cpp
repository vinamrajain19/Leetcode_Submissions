class Solution {
public:
    
    int dp[1001][1001];
    int f(int idx,int premx,vector<vector<int>> &v){
        if(idx == v.size()) return 0;
        
        if(dp[idx][premx] != -1) return dp[idx][premx]; 
        
        //no conflict cond
        int take = -1e9;
        int no = -1e9;
        if(v[idx][1] >= premx){
            take = max(v[idx][0] + f(idx+1,v[idx][1],v),f(idx+1,premx,v));
        }
        //conflict
        else{
            no = f(idx+1,premx,v); 
        }
        
        return dp[idx][premx] = max(take,no);
    }
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        vector<vector<int>> v;
       for(int i = 0;i<s.size();i++){
           v.push_back({s[i],a[i]});
       }
        sort(v.begin(),v.end());
        memset(dp,-1,sizeof(dp));
        return f(0,0,v);
    }
};