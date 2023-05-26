class Solution {
public:
    
    
    int f(const vector<int> &A) {
        int p = 1;
        int ans = -1e9;

        for(int i = 0 ;i<A.size();i++){
            p *= A[i];
           ans = max(ans,p);
            if(p == 0) p = 1;  

        }

        p = 1;

        for(int i = A.size()-1;i>=0;i--){
            p *= A[i];
            ans = max(ans,p);
            if(p == 0) p =1;
         }

         return ans;
    }
    
    int maxProduct(vector<int>& nums) {
        return f(nums);
    }
};