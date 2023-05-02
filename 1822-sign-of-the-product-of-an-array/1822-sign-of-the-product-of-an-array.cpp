class Solution {
public:
    int arraySign(vector<int>& nums) {
        int p = 0;
        int n = 0;
        
        for(auto it : nums){
            if(it == 0) return 0;
            
            else if(it < 0) n++;
        }
        
        if(n%2 == 1) return -1;
        return 1;
    }
};