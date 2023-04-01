class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        
        vector<int> dp(nums.size(),1);
        vector<int> hash(nums.size(),1);
        
        
        int mx = -1;
        int lastindex = -1;
        
        for(int i = 0;i<nums.size();i++){
            
            hash[i] = i;
            
            
            for(int j = 0;j<i;j++){
                if((nums[i] % nums[j]) == 0 and (dp[i] < 1 + dp[j])){
                    dp[i] = 1 + dp[j];
                    //cout<<nums[j]<<" ";
                    hash[i] = j;
                 }
            }
            
            //cout<<temp.size() <<" ";
            
            if(dp[i] > mx){
                //ans = temp;
                mx = dp[i];
                lastindex = i;
            }
        }
        
        ans.push_back(nums[lastindex]);
        
         while(hash[lastindex] != lastindex){ // till not reach the initialization value
            lastindex = hash[lastindex];
            ans.push_back(nums[lastindex]);    
         }
        
        return ans;
    }
};