class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s =0;
        int e =nums.size()-1;
        
        while(s<e){
            int mid = (s+e)/2;
            if(mid +1 < nums.size() and nums[mid] < nums[mid+1]){
                s = mid+1;
            }
            else if(mid - 1>= 0 and nums[mid-1] > nums[mid]){
                e = mid-1;
            }
            else return mid;
        }
        
        return s;
    }
};