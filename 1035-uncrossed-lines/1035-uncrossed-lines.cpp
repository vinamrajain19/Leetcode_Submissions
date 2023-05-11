class Solution {
public:
    
    int dp[501][501];
    
    int f(vector<int> &nums1,vector<int> &nums2,int idx1,int idx2){
        
        if(idx1 >= nums1.size() or idx2 >= nums2.size()) return 0;
        
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if(nums1[idx1] == nums2[idx2]){
            return dp[idx1][idx2] =  1 + f(nums1,nums2,idx1+1,idx2+1);
        }
        return dp[idx1][idx2] =  max(f(nums1,nums2,idx1+1,idx2),f(nums1,nums2,idx1,idx2+1));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return f(nums1,nums2,0,0);
    }
};