class Solution {
public:
    
    
    int f(vector<int> &nums,int s){
        if(s < 0) return 0;
        
        int i = 0;
        int j = 0;
        
        int sum = 0;
        int ans = 0;
        
        while(j < nums.size()){
            
            sum += nums[j];
            
            while(sum > s and i < nums.size()){
                sum -= nums[i];
                i++;
            }
            
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
         // S.C = O(N);
        
//         int ans = 0;
//         int sum = 0;
//         unordered_map<int,int> m;
//         m[0] = 1;
        
//         for(int i = 0;i<nums.size();i++){
//             sum += nums[i];
            
//             if(m.find(sum - goal) != m.end()){
//                 ans += m[sum-goal];
//             }
            
//             m[sum]++;
//         }
        
//         return ans;
        
        
        // S.C = O(1)
        
        return f(nums,goal) - f(nums,goal-1);
    }
};