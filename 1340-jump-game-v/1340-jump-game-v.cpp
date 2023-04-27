class Solution {
public:
    
    int dp[1005];
    
    int f(vector<int> &arr,int d,int idx){
        
        if(idx >= arr.size()) return -1e9;
        
        if(dp[idx] != -1) return dp[idx];
        
        int ans1 = 0;
    
        
         for(int i = idx+1;i<=min(idx+d,(int)arr.size()-1) and arr[idx] > arr[i];i++){
                ans1 = max(ans1,1 + f(arr,d,i));
        }
        
        for(int i = idx-1; i >= max(0,idx-d) and arr[i] < arr[idx];i--){
           
                ans1 = max(ans1,1 + f(arr,d,i));
        }
        
        
        
        return dp[idx] =  ans1;
        
    }
    
    int maxJumps(vector<int>& arr, int d) {
        int ans = 0;
        
        memset(dp,-1,sizeof(dp));
        
        for(int i = 0;i<arr.size();i++){
            ans = max(ans,1+f(arr,d,i));
        }
        
        return ans;
    }
};