class Solution {
public:

    int f(int ind, int diff, vector<int> &rods, int n, vector<vector<int>> &dp){
        if(ind==n){
            if(diff==0){
                return diff;
            }
            return -1e9;
        }

        if(dp[ind][diff+5000]!=-1) return dp[ind][diff+5000];

        int take1 = rods[ind]+f(ind+1,diff+rods[ind],rods,n,dp);
        int take2 = f(ind+1,diff-rods[ind],rods,n,dp);
        int nottake = f(ind+1,diff,rods,n,dp);
        
        return dp[ind][diff+5000]=max(nottake, max(take1, take2));
    }
    

    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        vector<vector<int>> dp(n+1, vector<int>(20001, -1));
        int ans = f(0,0,rods,n,dp);
        return ans;
    }
};