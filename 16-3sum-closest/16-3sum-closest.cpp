class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         int n = nums.size();  
        sort(nums.begin() , nums.end());  // sort the array to use the two pointers method
       int close = 1e9;
       int ans = -1;
		
        for(int i = 0 ; i < n; i++){
               
                int x = i+1 , y = n-1;
                
                while(x < y){
				
                    int sum = nums[i] + nums[x] + nums[y];
                    
                    if(close > abs(target - sum)){
                        close = abs(target-sum);
                        ans = sum;
                    }
                    
                    if(sum == target) return target;
                    else if(sum < target) x++;
                    else y--;
                }
        }
        return ans;
		
    }
};