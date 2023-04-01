//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long dp[50001][3];
    
    long long f(vector<long long> &p,int fee,int idx,int buy){
        if(idx >= p.size()) return 0;
        
        if(dp[idx][buy] != -1) return dp[idx][buy];
        
        if(buy){
            return dp[idx][buy] = max(-p[idx] + f(p,fee,idx+1,0) , f(p,fee,idx+1,1));
        }
        else return dp[idx][buy] =  max(p[idx] - fee + f(p,fee,idx+1,1),f(p,fee,idx+1,0));
    }
    
    long long maxProfit(vector<long long>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return f(prices,fee,0,1);
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        return maxProfit(prices,fee);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends