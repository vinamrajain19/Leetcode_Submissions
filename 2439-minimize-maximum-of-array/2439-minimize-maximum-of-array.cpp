class Solution {
public:
    
    //minimum value of the maximum integer -> Binary Search 
    
    int f(vector<int> nums,int m){
        long long sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i] - m;
            if(sum > 0) return false;
        }
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
        int s = 0;
        int e = 1e9;
        
        int ans = -1;
        while(s <= e){
            int m = (s+e)/2;
            
            if(f(nums,m)){
                ans = m;
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
        return ans;
    }
};