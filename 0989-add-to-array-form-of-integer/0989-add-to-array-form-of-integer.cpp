class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i = num.size()-1;
        
        vector<int> ans;
        int carry = 0;
        while(i >= 0 or k > 0 or carry){
            if(k){
                carry += k%10;
                k/=10;
            }
            
            
            if(i>=0) carry += num[i--];
            
            ans.push_back(carry%10);
            carry /= 10;
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};