// here while memoizing we add +1 to last because last is -1 sometimes and there is no index as -1.Adding +1 makes it zero.
class Solution {
public:
    
    
    int find(int ind,vector<int>&nums1,vector<int>&nums2,int last,vector<vector<int>>&dp)
    {
        if(ind==nums1.size())
        {
            return 0;
        }
        
        if(dp[ind][last+1]!=-1)
            return dp[ind][last+1];
        
        int ans=0;
        if(last==-1)
        {
            ans=max(ans,1+find(ind+1,nums1,nums2,0,dp));
            ans=max(ans,1+find(ind+1,nums1,nums2,1,dp));
            ans=max(ans,find(ind+1,nums1,nums2,-1,dp));
        }
        else
        {
            int val=0;
            if(last==0)
                val=nums1[ind-1];
            else
                val=nums2[ind-1];
            
            if(nums1[ind]>=val)
                ans=max(ans,1+find(ind+1,nums1,nums2,0,dp));
            
            if(nums2[ind]>=val)
                ans=max(ans,1+find(ind+1,nums1,nums2,1,dp));   
        }
        return dp[ind][last+1]=ans;
    }
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2)
    {
        vector<vector<int>>dp(nums1.size(),vector<int>(3,-1));// Max value of last can be when last_num is from nums2 
                                                             //so last=1 and add 1 so max last=2
        int ans=find(0,nums1,nums2,-1,dp);
        return ans;
    }
};