class Solution {
public:
   
    int minimumDeletions(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        
        int mn,mx;
        int x = 1e9;
        int y = -1e9;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] < x){
                x = nums[i];
                mn = i;
            }
            if(nums[i] > y){
                y = nums[i];
                mx = i;
            }
        }
        
        //case 1 ->  both left
        int a = 0;
        if(mn > mx) a = mn +1;
        else a = mx + 1;
        //case 2 -> both right
        int b = 0;
        if(mn > mx) b = nums.size() - mx;
        else b= nums.size() - mn;
        
        //case 3 - > both fron left right;
        int c = 0;
        if(mn > mx){
            c = nums.size() - mn + 1 + mx;
        }
        else c = nums.size() - mx +1+mn;
        
        return min({a,b,c});
        
        
    }
};