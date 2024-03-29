//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int dp[501][3][201];
    int f(vector<int> &prices,int idx,int buy,int cnt,int k){

        if(idx >= prices.size()) return 0;
        if(cnt == k) return 0;

        if(dp[idx][buy][cnt] != -1) return dp[idx][buy][cnt];

        int a = 0;
        int b = 0;
        if(buy){
            a = -prices[idx] + f(prices,idx+1,0,cnt,k);
            b = f(prices,idx+1,1,cnt,k);
        }
        else{
            a = prices[idx] + f(prices,idx+1,1,cnt+1,k);
            b = f(prices,idx+1,0,cnt,k);
        }

        return dp[idx][buy][cnt] = max(a,b);
    }
    int maxprofit(vector<int>& prices,int k) {
        memset(dp,-1,sizeof(dp));
        return f(prices,0,1,0,k);
    }
    
    
    int mxProfit(int k, vector<int>& prices) {
        return maxprofit(prices,k);
    }
    
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<int> v;
        for(int i = 0;i<N;i++){
            v.push_back(A[i]);
        }
        return mxProfit(K,v);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends