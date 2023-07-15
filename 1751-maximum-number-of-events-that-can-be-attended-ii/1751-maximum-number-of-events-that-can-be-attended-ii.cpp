class Solution {
public:

    static bool cmp(vector<int> &a,vector<int> &b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    
    
    int f(vector<vector<int>> &e,int k,int idx,vector<vector<int>> &dp){
        if(idx >= e.size()) return 0;
        
        if(k == 0) return 0;
        
        if(dp[idx][k] != -1) return dp[idx][k];
        
        int j = idx+1;
        while(j < e.size() and e[idx][1] >= e[j][0]){
            j++;
        }
        
        int no = f(e,k,idx+1,dp);
        int t = e[idx][2] + f(e,k-1,j,dp);
        
        return dp[idx][k] = max(no,t);
    }
    
    int maxValue(vector<vector<int>>& e,int k) {
        vector<vector<int>> dp(e.size()+1,vector<int>(k+1,-1));
       sort(e.begin(),e.end(),cmp);
       return f(e,k,0,dp);
    }
};