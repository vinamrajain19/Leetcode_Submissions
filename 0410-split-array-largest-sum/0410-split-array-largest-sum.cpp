class Solution {
public:
    
    bool ispossible(vector<int> &nums,int curr,int m){
		int total=1;
		int sum=0;
		for(int i=0;i<nums.size();i++){
		   sum+=nums[i];
		   if(sum>curr){
			   sum=nums[i];
			   total++;
		   }
			if(nums[i]>curr) return false;
		}
		return total<=m;
	}
    
    
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        for(auto it : nums) sum += it;
        
        int s = *max_element(nums.begin(),nums.end());
        
        int e = sum;
        
        int ans = 0;
        while(s <= e){
            int m = (s+e)/2;
            
            if(ispossible(nums,m,k)){
                ans = m;
                e = m-1;
            }
            else s = m+1;
        }
        
        return ans;
    }
};