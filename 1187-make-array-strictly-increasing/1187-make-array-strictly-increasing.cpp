class Solution {
public:
    
    int dp[2001][2001];
    
    int f(vector<int> &arr1,vector<int> &arr2,int i,int j,int prev){
        
        if(i == arr1.size()) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        
        int ans = INT_MAX-1;
        int modify = INT_MAX-1;
        int notmodify = INT_MAX-1;
        
        // two option -> either modify it or not
        if(arr1[i] > prev){
            
            // not modify  
            notmodify = f(arr1,arr2,i+1,j,arr1[i]);
            
            // modify
            j = upper_bound(arr2.begin()+j,arr2.end(),prev) - arr2.begin();
            if(j < arr2.size()) modify = 1 + f(arr1,arr2,i+1,j+1,arr2[j]);
            
            ans = min(modify,notmodify);
        }
        
        // only one option modify it
        else{
            j = upper_bound(arr2.begin()+j,arr2.end(),prev) - arr2.begin();
            
            if(j < arr2.size()) modify = 1 + f(arr1,arr2,i+1,j+1,arr2[j]);
            
            ans = min(ans,modify);
        }
        
        return dp[i][j] = ans;
        
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        memset(dp,-1,sizeof(dp));
        sort(arr2.begin(),arr2.end());
        int ans = f(arr1,arr2,0,0,-1);
        
        if(ans >= INT_MAX-1) return -1;
        return ans;
    }
};