class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
    
        int prev = nums[0];
        int prev2 = 0;
        
        for(int i = 1;i<n-1;i++){
            int pick = nums[i];
            if(i>=2){
                pick += prev2;
            }
            
            int notpick =  prev;
            
            int curr = max(pick,notpick);
            
            prev2 = prev;
            prev = curr;
        }
        
        int ans1 = prev;
        prev = 0;
        prev2 = 0;
        
        for(int i = 1;i<n;i++){
            int pick = nums[i];
            if(i>=2){
                pick += prev2;
            }
            int notpick = prev;
            
            int curr = max(pick,notpick);
            
            prev2 = prev;
            prev = curr;
        }
        
        
        return max(ans1,prev);
    }
};