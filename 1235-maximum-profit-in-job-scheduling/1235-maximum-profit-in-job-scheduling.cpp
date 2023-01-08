class Solution {
public:
    static bool cmp(vector<int> &a,vector<int > &b){
        return a[0] < b[0];
    }
    
    int f(int idx,int last,vector<vector<int>> &v,vector<int> &dp){
        
        while(idx < v.size() and last > v[idx][0]){
            idx++;
        }
        
        if(idx >= v.size()) return 0;
        
        
        if(dp[idx] != -1) return dp[idx];
        
      
        
        int take = v[idx][2] + f(idx+1,v[idx][1],v,dp);
        int no = f(idx+1,last,v,dp);
        
        return dp[idx] = max(take,no);
    }
    
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        
        vector<vector<int>> v;
        
        for(int i = 0;i<s.size();i++){
            v.push_back({s[i],e[i],p[i]});
        }
        
        sort(v.begin(),v.end(),cmp);
        vector<int> dp(s.size(),-1);
        return f(0,0,v,dp);
    }
};