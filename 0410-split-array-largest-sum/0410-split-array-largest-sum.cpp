class Solution {
public:
    
    bool f(vector<int> &nums,int k,int mid){
        int x = 0;
        int grp = 1;
        
        for(int i = 0;i<nums.size();i++){
            if(x + nums[i] <= mid){
                x += nums[i];
            }
            else{
                grp++;
                if(grp > k or nums[i] > mid) return false;
                x = nums[i];
            }
        }
        
        return true;
    }
    
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        for(auto it : nums) sum += it;
        
        int s = 0;
        int e = sum;
        
        
        int ans = -1;
        while(s <= e){
            int m = (s+e) >> 1;
            
            if(f(nums,k,m)){
                ans = m;
                e = m-1;
            }
            else s = m+1;
        }
        
        return ans;
    }
};