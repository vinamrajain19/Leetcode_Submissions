//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


int dp[100001][3][3];
    int f(vector<int> &prices,int idx,int buy,int cnt){

        if(idx >= prices.size()) return 0;
        if(cnt == 2) return 0;

        if(dp[idx][buy][cnt] != -1) return dp[idx][buy][cnt];

        int a = 0;
        int b = 0;
        if(buy){
            a = -prices[idx] + f(prices,idx+1,0,cnt);
            b = f(prices,idx+1,1,cnt);
        }
        else{
            a = prices[idx] + f(prices,idx+1,1,cnt+1);
            b = f(prices,idx+1,0,cnt);
        }

        return dp[idx][buy][cnt] = max(a,b);
    }
    int maxprofit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return f(prices,0,1,0);
    }
int maxProfit(vector<int>&price){
    //Write your code here..
    return maxprofit(price);
    
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends