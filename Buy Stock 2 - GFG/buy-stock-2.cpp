//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //long long dp[100004][];
    
   
    
    long long maximumProfit(vector<long long>&p, int n) {
        // Code herer
        long long ans=0,i,mn=p[0];
        for(i=1;i<n;i++){
            if(p[i]>mn){
                ans+=(p[i]-mn);
                mn=p[i];
            }
            else mn=min(mn,p[i]);
        }
        return ans;
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
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends