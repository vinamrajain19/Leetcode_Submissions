class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int pos=0, neg=1;
        for(int n : nums)
        {
            if(n<0)
            {
                ans[neg]=n;
                neg+=2;
            }
            else
            {
                ans[pos]=n;
                pos+=2;
            }
        }
        return ans;
        
    }
    
};