//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

int rec(int curr, vector<vector<int>>&cost, int mask, int n,vector<vector<int>>&dp)
  {
        if(mask== ((1<<n)-1))
        {
              return cost[curr][0];
        }
        
        if(dp[curr][mask]!=-1)
        return dp[curr][mask];
        
        int res=INT_MAX;
        
        for(int city=0;city<n;city++)
        {
             if( (mask&(1<<city))==0)
             {
                    int temp= cost[curr][city]+ rec(city,cost,mask|(1<<city),n,dp);
                    
                    res=min(res,temp);
             }
        }
        dp[curr][mask] =res;
        return dp[curr][mask];
  }
int total_cost(vector<vector<int>>cost){
    // Code here
    int n=cost.size();
    vector<vector<int>>dp(n+5,vector<int>((1<<n),-1));
       int mask=1;
       return rec(0,cost,mask,n,dp);
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends