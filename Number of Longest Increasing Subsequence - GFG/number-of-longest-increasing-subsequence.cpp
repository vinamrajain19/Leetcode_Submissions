//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> c(nums.size(),1);
        int mx = -1e9;
        
        for(int i = 0;i<nums.size();i++){
            for(int j = 0;j<i;j++){
                if(nums[i] > nums[j] and dp[i] < 1 + dp[j]){
                    dp[i] = 1 + dp[j];
                    c[i] = c[j];
                }
                else if(nums[i] > nums[j] and dp[i] == 1 + dp[j]){
                    c[i] += c[j];
                }
            }
            
            mx = max(mx,dp[i]);
        }
        
        int ans = 0;
        
        
        for(int i = 0;i<nums.size();i++){
            if(dp[i] == mx){
                ans += c[i];
            }
        }
        
        return ans;
        
    }
    int NumberofLIS(int n, vector<int>&arr) {
        // Code here
        return findNumberOfLIS(arr);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends