class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        if(nums.size() < 4) return {};
        
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i<nums.size();i++){
            
            int sum_1 = target - nums[i];
            
            for(int j = i+1;j<nums.size();j++){
                
                long long  sum_2 = (long long)sum_1 - (long long)nums[j];
                
                
                int x = j+1;
                int y = nums.size()-1;
                
                while(x < y){
                    long long sum = (long long)nums[x] + (long long)nums[y];
                    
                    if(sum_2 == sum){
                        
                        ans.push_back({nums[i],nums[j],nums[x],nums[y]});
                        
                        while(x < y and nums[x] == nums[x+1]){
                            x++;
                        }
                        
                        while(x < y and nums[y] == nums[y-1]){
                            y--;
                        }
                        
                        x++;
                        y--;
                    }
                    else if(sum_2 < sum) y--;
                    else x++;
                }
                
               while(j + 1 < nums.size() && nums[j + 1] == nums[j]) ++j;
            }    
            
            while(i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;

        }
        
        return ans;
        
    }
};