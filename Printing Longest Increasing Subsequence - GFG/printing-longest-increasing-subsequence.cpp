//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  vector<int> an;

    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int> dp(n,1);
        vector<int> hash(n,1);
        int lastindex = -1;
        int ans = -1;
        for(int i = 0;i<n;i++){
            hash[i] = i;
            for(int prev = 0;prev < i;prev++){
                  if(arr[prev]<arr[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                   }
            }
            
            if(dp[i] > ans){
                ans = dp[i];
                lastindex = i;
            }
        }
        
        an.push_back(arr[lastindex]);
        
        while(hash[lastindex] != lastindex){
            lastindex = hash[lastindex];
            an.push_back(arr[lastindex]);
        }
        
        reverse(an.begin(),an.end());
        
        return an;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends