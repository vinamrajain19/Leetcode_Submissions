// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    
    int dp[501][2001];
    
    int f(vector<int> &nums,int k,int idx,int rem){
        if(idx == nums.size()) return 0;
        
        if(dp[idx][rem] != -1) return dp[idx][rem];
        
        // we can add particular char or not  ->  2 option -> add it go gor next one or this is complete include it
        if(nums[idx] > rem)
           return dp[idx][rem] =  (rem+1)*(rem+1) + f(nums,k,idx+1,k-nums[idx]-1);
          
        else return dp[idx][rem] =  min(f(nums,k,idx+1,rem-nums[idx]-1),(rem+1) * (rem+1) + f(nums,k,idx+1,k - nums[idx]-1));
        
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        memset(dp,-1,sizeof(dp));
        return f(nums,k,0,k);
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends