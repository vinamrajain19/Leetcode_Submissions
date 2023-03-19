class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        
        int f = -1;
        int last = -1;
        while(s <= e){
            int mid = (s+e)/2;
            
            if(nums[mid] < target){
                s = mid+1;
            }
            else if(nums[mid] == target){
                f = mid;
                e = mid-1;
            }
            else e = mid-1;
        }
        
        e = nums.size()-1;
        
         while(s <= e){
            int mid = (s+e)/2;
            
            if(nums[mid] < target){
                s = mid+1;
            }
            else if(nums[mid] == target){
                last = mid;
                s = mid+1;
            }
            else e = mid-1;
        }
        
        return {f,last};
    }
};