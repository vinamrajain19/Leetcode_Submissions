class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        // maxmimize the longest subarray sum with sum is totalsum - x -> return n-len
        
        int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum == x) return nums.size();
        if(sum < x) return -1;
        
        int i  = 0;
        int j = 0;
        int tar = sum - x;
        int y = 0;
        int len = 0;
        
        while(j<nums.size()){
            y+=nums[j];
            
            if(y<tar){
                j++;
            }
            else if(y == tar){
                len = max(len,j-i+1);
                j++;
            }
            else if(y>tar){
                while(y>tar){
                    y-=nums[i];
                    i++;
                }
                if(y == tar) len = max(len,j-i+1);
                j++;
            }
        }
        
        return (len == 0) ? -1 : (nums.size() - len);
        
    }
};