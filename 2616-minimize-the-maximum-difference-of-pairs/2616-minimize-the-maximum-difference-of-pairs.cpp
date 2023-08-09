class Solution {
public:
    
    bool f(vector<int> &nums,int m,int p){
        int c = 0;
        
        for(int i = 1;i<nums.size();i++){
            if(nums[i] - nums[i-1] <= m){
                c++;
                i++;
            }
            
            if(c >= p) return true;
        }
        
        if(c >= p) return true;
        return false;
        
        
    }
    
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        
        int s = 0;
        int e = nums[nums.size()-1];
        
        int ans = 0;
        
        while(s <= e){
            int m = (s+e)/2;
            
            if(f(nums,m,p)){
                ans = m;
                e =m-1;
            }
            else s = m+1;
        }
        
        return ans;
    }
};