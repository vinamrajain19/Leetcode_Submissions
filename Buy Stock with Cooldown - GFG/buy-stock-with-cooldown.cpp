//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
  
    
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<long long> curr(2,0);
        vector<long long> f1(2,0);
        vector<long long> f2(2,0);
        
       // int buy = 1;
        
        for(int i = n-1;i>=0;i--){
            
            for(int buy = 0;buy<=1;buy++){
           if(buy == 0){
               curr[buy] = max(-prices[i] + f1[1],f1[0]);
           }
           else{
               curr[buy] = max(prices[i] + f2[0] , f1[1]);
           }
            }
            
            f2 = f1;
            f1 = curr;
           
        }
        
        return curr[0];
        
        
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