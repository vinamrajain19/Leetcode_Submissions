class Solution {
public:
   
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        
        int ans = 0;
        
        int cnt = 0;
        
        int x = 0;
        
        while(j < nums.size()){
            
            if(nums[j] % 2 != 0){
                cnt++;
                x = 0;
            }
            
            while(cnt == k){
                x++;
                if(nums[i++] % 2 == 1){
                    cnt--;
                }
            }
            
            ans += x;
            j++;
        } 
        return ans;
    }
    
};